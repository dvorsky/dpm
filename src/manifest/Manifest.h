#include <string>
#include "memory"
#include "../lib/cpptoml/cpptoml.h"
#ifndef DPM_SRC_MANIFEST_MANIFEST_H
#define DPM_SRC_MANIFEST_MANIFEST_H

#endif //DPM_SRC_MANIFEST_MANIFEST_H

class Manifest {
public:
  std::string name;
  std::string author;
  std::string version;
  std::string bin;

  Manifest();
  void read_manifest_data(std::shared_ptr<cpptoml::table> manifest);
};