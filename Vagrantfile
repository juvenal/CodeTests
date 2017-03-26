# -*- mode: ruby -*-
# vi: set ft=ruby :

# Set default Vagrantfile config version
VAGRANTFILE_API_VERSION = '2'

# Set our default provider for this Vagrantfile to 'vmware_fusion', this setting
# can be vmware_appcatalyst, vmware_fusion and vmware_desktop for vmware
ENV['VAGRANT_DEFAULT_PROVIDER'] = 'vmware_fusion'

# Provisioning script
@script = <<SCRIPT
# Update the system
dnf -y update --exclude=kernel*
dnf -y install vim wget
# Fix the locale problem
echo "LANG='en_US.utf8'
LC_CTYPE='en_US.utf8'" > /etc/locale.conf
# Install development toolchain
dnf -y install make flex bison gcc gcc-c++
dnf -y install gcc-objc gcc-objc++ gcc-gfortran
dnf -y install gcc-go golang golang-bin golang-src
dnf -y install llvm llvm-libs llvm-doc llvm-static clang
# Set vagrant user environment
mv /home/vagrant/linux.iso /root && chown root:root /root/linux.iso
# Get custom .bashrc
wget -O /etc/skel/.bashrc https://raw.github.com/juvenal/dotfiles/master/.bashrc
cp /etc/skel/.bashrc /root
cp /etc/skel/.bashrc /home/vagrant
# Prepare the MOTD file
echo "

Vagrant box running Fedora 23

Multiple toolchains installed:
C/C++, Obj-C/Obj-C++, Go, Fortran, LLVM and clang available...

Use them wisely ;-)

" > /etc/motd
echo "*** Machine ready for usage!"
SCRIPT

# Machine definition
node = { machine: 'binary-learn',
         hostname: 'fedora23-amd64',
         box: 'v2lab/fedora23-64' }

# This are the boxes configuration themselves
Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.define node[:machine] do |node_config|
    # Basic configs for box and hostname
    node_config.vm.box = node[:box]
    node_config.vm.hostname = node[:hostname]
    node_config.vm.synced_folder ".", "/home/vagrant/binary-learn"
    node_config.vm.network 'private_network', type: 'dhcp'
    node_config.vm.provision 'shell', inline: @script

    # Config the VM capacity - memory and CPU
    node_config.vm.provider 'vmware_fusion' do |vmset|
      vmset.cpus = '2'
      vmset.memory = '1024'
    end
  end
end
