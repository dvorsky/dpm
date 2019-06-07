
#include "Manifest.h"
#include "../lib/cpptoml/cpptoml.h"

Manifest::Manifest() = default;

void Manifest::read_manifest_data(const std::shared_ptr<cpptoml::table> config) {
  auto package_table = config->get_table("package");

  cpptoml::option<std::string> name_value = package_table->get_as<std::string>("name");
  auto author_value = package_table->get_as<std::string>("author");
  auto version_value= package_table->get_as<std::string>("version");
  auto bin_value= package_table->get_as<std::string>("bin");

  if (name_value) {
    this->name = name_value.operator*();
  }

  if (author_value) {
    this->author = author_value.operator*();
  }

  if (version_value) {
    this->version = version_value.operator*();
  }

  if (bin_value) {
    this->bin = bin_value.operator*();
  }
}

void Manifest::setBin(const cpptoml::option<std::string> &Bin) {
  if (Bin) {
    this->bin = Bin.operator*();
  }
}
