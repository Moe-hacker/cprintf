sudo debootstrap --foreign --arch=loong64 --variant=buildd --include=debian-ports-archive-keyring --verbose --components=main --resolve-deps --extra-suites=unreleased unstable ./debian http://ftp.ports.debian.org/debian-ports
sudo cp /usr/bin/qemu-loongarch64-static debian/usr/bin/
cat <<EOF >>./debian/build.sh
rm /etc/resolv.conf
echo nameserver 1.1.1.1 > /etc/resolv.conf
apt update
apt install -y wget make clang git libseccomp-dev libcap-dev libc-dev binutils
apt install -y upx
git clone https://github.com/moe-hacker/cprintf
cd cprintf
./gen-config -s
make
strip cprintf
tar -cvf ../loong64.tar ./cprintf ./LICENSE
EOF
sudo chmod +x ./debian/build.sh
./ruri/ruri -p -a loong64 -q /usr/bin/qemu-loongarch64-static ./debian /debootstrap/debootstrap --second-stage
sudo ./ruri/ruri -p -a loong64 -q /usr/bin/qemu-loongarch64-static ./debian /bin/sh /build.sh
cp ./debian/loong64.tar ../loongarch64.tar
