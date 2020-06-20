1. Download and install toolchain

  $ curl https://static.dev.sifive.com/dev-tools/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14.tar.gz

2. Follow instruction on https://github.com/olofk/serv/

3. Configure and build NuttX

  $ mkdir ./nuttx; cd ./nuttx
  $ git clone https://bitbucket.org/nuttx/nuttx.git
  $ git clone https://bitbucket.org/nuttx/apps.git
  $ cd nuttx
  $ make distclean
  $ ./tools/configure.sh servant_verilator:nsh
  $ make

6. Run fusesoc run --target=verilator_tb servant --uart_baudrate=57600 --firmware=nuttx.hex