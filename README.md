# Hello, Codespaces

This repository contains an application that prints "Hello, Codespaces!" and a counter value via semihosting output on
an [Arm FVP](https://developer.arm.com/Tools%20and%20Software/Fixed%20Virtual%20Platforms) simulation model
(Cortex-M3).

A [codespace](https://docs.github.com/en/codespaces/about-codespaces/what-are-codespaces) is a development environment
that's hosted in the cloud. Each codespace you create is hosted by GitHub in a Docker container, running on a virtual
machine. Regardless of your local operating system, your codespace will run in a Linux environment. You can connect to
your codespaces from your browser, from Visual Studio Code, or by using GitHub CLI.

## Quick Start

1. Click on **Use this Template** (in the top right corner) and select **Create a new Repository**.
2. Enter a name for the new repository and click on **Create repository**. The new repository opens in your browser.
3. Click on the drop down next to **<> Code** and select **Codespaces**.
4. Click on **Create codespace on main**.

> [!NOTE]
> The first time you create the Codespace will take a while as it installs the tools as described in the
> [`devcontainer.json`](.devcontainer/devcontainer.json) file.

During the process, you will see a pop up like this:

![Arm Environment Activation](./images/environment-activation.png)

Click on **Allow For Current Workspace**. This will install the tools specified in the
[`vcpkg-configuration.json`](./vcpkg-configuration.json) file automatically into your codespace.

When the installation finishes, you will see a pop up in the bottom right corner:

![Manage Arm License](./images/manage-arm-license.png)

Click on **Manage Arm license** to select from the available options. For evaluation purposes, you can use the Arm Keil
MDK-Community edition:

![Activate Arm Keil MDK Community Edition](./images/mdk-community.png)

> [!NOTE]
> If you missed the pop up, you can activate a license by clicking on the
> ![No Arm License](./images/no-arm-license.png) notification in the status bar.

## Build and Run

The project is configured for execution on an Arm Cortex-M3 FVP. Using a model removes the requirement for a physical
hardware board. This enables software testing directly on GitHub repositories.

1. Open the ![CMSIS View](./images/cmsis-view.png) **CMSIS** view.
2. If the current target set context **avh** in the status bar shows a red background, click on the three dots and
   select **Refresh (reload packs, update RTE)**. This will trigger a project update with the arm tool license
   you have added previously.
3. Click on ![Build button](./images/build.png) **Build solution** to start the build process. The build should finish
   without errors or warnings.
4. Click on ![Run button](./images/run.png) **Load & Run application** to run the image on the simulation model. The
   **Terminal** shows the output:

```txt
 *  Executing task: FVP_MPS2_Cortex-M3 -f fvp-config.txt --simlimit 120 -a out/hello/avh/debug/hello.axf  

Info: FVP_MPS2_Cortex_M3: telnetterminal0: Listening for serial connection on port 5000
Info: FVP_MPS2_Cortex_M3: telnetterminal1: Listening for serial connection on port 5001
Info: FVP_MPS2_Cortex_M3: telnetterminal2: Listening for serial connection on port 5002
Hello, Codespaces! 0
Hello, Codespaces! 1
Hello, Codespaces! 2
Hello, Codespaces! 3
Hello, Codespaces! 4
Hello, Codespaces! 5
Hello, Codespaces! 6
Hello, Codespaces! 7
Hello, Codespaces! 8
Hello, Codespaces! 9
Hello, Codespaces! 10
Hello, Codespaces! 11
...

Info: Simulation is stopping. Reason: Simulated time has been exceeded.
Info: /OSCI/SystemC: Simulation stopped by user.
```

> [!NOTE]
> The simulation stops automatically after 120 seconds runtime.

## Repository Structure

```txt
  📦
  ┣ 📂 .devcontainer                    Development container control files
     ┗ 📄 devcontainer.json              Installs the required VS Code extensions (Keil Studio Pack)
  ┣ 📂 .vscode                          VS Code specific settings files
     ┗ 📄 tasks.json                     Load & run commands to start the Arm FVP model
  ┣ 📂 hello                            Project files
     ┣ 📂 RTE                            Run-time environment related files
     ┣ 📄 hello.cproject.yml             Project file in CMSIS solution format
     ┗ 📄 main.c                         C code
  ┣ 📂 images                           Images for this README.md file
  ┣ 📄 .gitignore                       List of files not to be committed to Git
  ┣ 📄 fvp-config.txt                   Arm FVP configuration file 
  ┣ 📄 hello_codespaces.csolution.yml   CMSIS Solution file 
  ┣ 📄 LICENSE                          Apache 2.0 license file
  ┣ 📄 README.md                        This file
  ┗ 📄 vcpkg-configuration.json         Tools configuration file
```
