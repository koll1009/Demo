Set-VMSwitch WSL -NetAdapterName Wi-Fi
sudo ip a flush eth0
sudo ip a add 192.168.31.24/24 dev eth0
sudo ip r add default via 192.168.31.1
sudo sh -c 'echo "nameserver 192.168.31.1" > /etc/resolv.conf'
sudo insmod /usr/src/WSL2-Linux-Kernel-linux-msft-5.4.72/drivers/uio/uio_hv_generic.ko
sudo mount -t hugetlbfs -o pagesize=2M none /mnt/hugepages/
sudo sh -c "echo 256 >  /sys/kernel/mm/hugepages/hugepages-2048kB/nr_hugepages"
 sudo driverctl -b vmbus set-override $(basename $(readlink /sys/class/net/eth0/device)) uio_hv_generic
