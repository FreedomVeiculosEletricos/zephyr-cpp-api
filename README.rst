
Zephyr C++ API
##############

This repository is used for Zephyr C++ API development. It have all necessary source code, samples
and tests. This repository allow use of ``native_posix_64`` for development purposes.

Using Zephyr SDK as development environment
*******************************************

The you must follow the steps at `Zephyr RTOS getting started`_.

.. _Zephyr RTOS getting started:
  https://docs.zephyrproject.org/latest/develop/getting_started/index.html

Using Nix as development environment
************************************

To provide a consistent environment across developers and the CI we rely on Nix. The installation is
very easy and works in any Linux distribution but it requires few packages available. For
Debian/Ubuntu based distributions you can use

.. code-block:: shell

  sudo apt install -y curl rsync zsh xz-utils git-core

Next, to install the Nix daemon inside the existing operating system you can run:

.. code-block:: shell

  curl -L https://nixos.org/nix/install | sh -s -- --daemon

  # Enable Nix Flakes support
  mkdir -p ~/.config/nix
  echo 'experimental-features = nix-command flakes' > ~/.config/nix/nix.conf

After the Nix is installed, you can start the development environment using:

.. code-block:: shell

   nix develop

Inside the shell, all SDK is available for use, as can be seen below:

.. code-block:: shell

   % nix develop
   [user@machine:~/zephyr-c++-api/c++-api]$ west --version
   West version: v0.14.0
