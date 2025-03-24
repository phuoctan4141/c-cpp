# SECURE BOX

## Sơ đồ mạng truyền RTSP từ Camera IP đến VMS

```mermaid
graph TD
    subgraph Cloud
        VMS[VMS Server]
    end

    subgraph Router[SECURE BOX]
        eth0[eth0 - WAN] -- Gửi dữ liệu RTSP --> Cloud
        eth1[eth1 - LAN] -- Cấp DHCP & Kết nối Switch --> Switch1[Switch]
        DHCP[DHCP Server 192.168.7.10 - 192.168.7.100]
    end

    subgraph Camera IP
        Switch1 -- Kết nối IP Cameras --> Camera1[IP Camera 1]
        Switch1 -- Kết nối IP Cameras --> Camera2[IP Camera 2]
        Switch1 -- Kết nối IP Cameras --> CameraN[IP Camera N]
    end

    DHCP -- Cấp IP --> Camera1
    DHCP -- Cấp IP --> Camera2
    DHCP -- Cấp IP --> CameraN

    Camera1 -- RTSP Stream --> eth1
    Camera2 -- RTSP Stream --> eth1
    CameraN -- RTSP Stream --> eth1

```

## Cài đặt DHCP server cho ETH1

```sh
cat > /etc/network/interfaces << EOF
# The loopback interface
auto lo
iface lo inet loopback

# Internet interface
auto eth0
iface eth0 inet dhcp

# LAN interface
auto eth1
iface eth1 inet static
        address 192.168.7.2
        netmask 255.255.255.0
        network 192.168.7.0
        gateway 192.168.7.1

EOF
```
