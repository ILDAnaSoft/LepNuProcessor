# LepNuProcessor

Based on *iLCsoft*.

*Marlin* processor and plotting framework to analyze *charged lepton* + *neutrino* pairs in the jets of the event. The *TrueJet* processor is applied to obtain correctly clustered, reconstructed jets.

## Code structure

The following subdirectories are included:
- **CMakeLists**: Different versions of the CMakeLists.txt for different *iLCsoft* versions.
- **InformationStorages**: Code of the class in which information is stored which is relevant for the analysis.
- **include**: Headers of the Marlin processor.
- **macros**: Source code for a slighlty version of *ROOT* s hadd (able to add files containing my custom class).
- **plotting**: Code of plotting framework, individual plotters and their output.
- **scripts**: (Mostly) bash scripts which intended for the building/execution of the code and job handling. Scripts intended to be run directly have the syntax *run_...* .
- **src**: Source code of the Marlin processor.
- **xml**: Store steering files for Marlin jobs.

## Running the code

### Making changes in the source code

Whenever any of the source code is changed it must be recompiled. This can be done easily from within the *scripts* directory using the *run_make.sh* script:

```sh
./run_make.sh
```

### Running Marlin

The Marlin processors can be run from the *scripts* directory using the *run_class.sh* script:

```sh
./run_class.sh class(e.g. 6f_2l4q) Marlin
```
This will start jobs using the template steering file in the *xml/steering_files/template_files* directory on HTCondor.

The input files are kept in and read out from a local sqlite database in *scripts/event_file_database.db*.

The output will be *.root* files containing the custom C++ class defined in the InformationStorage directory.

### Running the plotting framework

Using the framework in the *plotting* directory the *.root* files can be analyzed and the results plotted.

It can be run from within the *scripts* directory using the *run_plotting.sh* script:

```sh
./run_plotting.sh
```

## Disclaimer

(At the end so you don't run away immediately...)

This README only provides a rough idea of the code used in this analysis. Some things (especially those set in my local shell environment) may actually be missing from the code. If you try using some of my code and you have a specific problem: 1. Yell at the gods (always a good idea), 2. Drop me a message.
