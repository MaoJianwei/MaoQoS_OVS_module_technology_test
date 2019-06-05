sudo ovs-ofctl -O OpenFlow13 add-flow s1 in_port=2,eth_type=0x0800,nw_proto=6,tcp_src=1355,priority=30,actions=set_queue:3,output:1
sudo ovs-ofctl -O OpenFlow13 add-flow s1 in_port=1,eth_type=0x0800,nw_proto=6,tcp_dst=1355,priority=30,actions=set_queue:3,output:2
sudo ovs-ofctl -O OpenFlow13 add-flow s1 in_port=2,eth_type=0x0800,nw_proto=17,udp_dst=5001,priority=60,actions=set_queue:2,output:1
sudo ovs-ofctl -O OpenFlow13 add-flow s1 in_port=2,eth_type=0x0800,nw_proto=17,priority=10,actions=set_queue:3,output:1

sudo ovs-ofctl -O OpenFlow13 add-flow s1 in_port=1,priority=3,actions=output:2
sudo ovs-ofctl -O OpenFlow13 add-flow s1 in_port=2,priority=3,actions=output:1

sudo tc qdisc add dev s1-eth1 root handle 1 htb default 3
sudo tc class add dev s1-eth1 parent 1 classid 2 htb rate 30mbit ceil 30mbit
sudo tc class add dev s1-eth1 parent 1:2 classid 1:3 htb rate 1kbit ceil 30mbit
sudo tc class add dev s1-eth1 parent 1:2 classid 1:4 htb rate 14mbit ceil 30mbit
sudo tc qdisc add dev s1-eth1 parent 1:3 handle 5 htb
sudo tc qdisc add dev s1-eth1 parent 1:4 handle 6 htb

sudo tc qdisc add dev s1-eth2 root handle 1 htb default 3
sudo tc class add dev s1-eth2 parent 1 classid 2 htb rate 30mbit ceil 30mbit
sudo tc class add dev s1-eth2 parent 1:2 classid 1:3 htb rate 1kbit ceil 30mbit
sudo tc class add dev s1-eth2 parent 1:2 classid 1:4 htb rate 14mbit ceil 30mbit
sudo tc qdisc add dev s1-eth2 parent 1:3 handle 5 htb
sudo tc qdisc add dev s1-eth2 parent 1:4 handle 6 htb
