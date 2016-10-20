echo 'Adding PPAs...'
add-apt-repository -y ppa:ubuntu-toolchain-r/test
echo 'Updating packages list...'
apt-get -y update
echo 'Installing packages...'
apt-get -y install g++-6
apt-get -y install gtkmm-3.0
