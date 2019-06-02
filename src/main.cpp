#include <iostream>
#include "filesystem"

#include <fmt/format.h>

#include "lib/cpptoml/cpptoml.h"
#include "lib/cxxopts/cxxopts.hpp"
#include "manifest/Manifest.h"

#define MANIFEST_FILE "package.toml"

int main(int argc, char *argv[]) {
  cxxopts::Options options("DPM", "deno package manager");
  options.add_options()
      ("debug", "Enable debugging")
      ("d, dir", "Package directory", cxxopts::value<std::string>());

  auto result = options.parse(argc, argv);

  std::string package_path;

  if (result["dir"].count() != 0) {
    package_path = result["dir"].as<std::string>();
  }

  if (std::filesystem::is_directory(package_path) == false) {
    std::cerr << fmt::format("Error:\nNot a directory: {}", package_path) << std::endl;
    return 1;
  }

  if (std::filesystem::path(package_path).is_absolute() == false) {
    package_path = std::filesystem::absolute(package_path);
  }

  // Test if parsing works and I can read config lines
  try {
    auto config = cpptoml::parse_file(fmt::format("{}/{}", package_path, MANIFEST_FILE));
  } catch (...) {
    std::cerr << "Error:\nCould not read package.toml" << std::endl;
    return 1;
  }

  auto *manifest = new Manifest();

  if (config) {
    manifest->read_manifest_data(config);
  }

  return 0;
}