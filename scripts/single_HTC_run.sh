#!/bin/bash

source /afs/desy.de/user/b/beyerjac/flc/load_current_software_versions.sh

processor_dir=/afs/desy.de/user/b/beyerjac/flc/VBS/nu_correction_processor
PROJECTNAME=LepNuProcessor
libname=$processor_dir"/lib/lib$PROJECTNAME"
export MARLIN_DLL=${MARLIN_DLL}:${libname}.so

cd ${processor_dir}/xml/$1
Marlin $2
