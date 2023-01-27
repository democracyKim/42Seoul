# Let's Start Born2beRoot!
ChatGPT helped me with this assignment.
## Before starting the project
### What is a virtual machine and why we use it?
A virtual machine (VM) is a software-based simulation of a physical computer. It allows you to run an operating system and its applications in a virtual environment on your computer. VMs are often used for testing, development, and running multiple operating systems concurrently on the same physical machine.

There are several benefits to using virtual machines:

1. Isolation: Each virtual machine runs in its own isolated environment, so one VM can't interfere with another. This can be useful for testing software or running applications that may be unstable or have security vulnerabilities.
2. Compatibility: VMs allow you to run different operating systems on the same hardware, so you can use software that may not be compatible with your host operating system.
3. Resource allocation: VMs allow you to allocate resources such as CPU, memory, and storage to each VM, so you can customize the resources available to each virtual machine.
4. Portability: VMs can be easily moved between physical machines, making it easy to migrate them to new hardware or to a cloud environment.

Overall, virtual machines offer a convenient and flexible way to run multiple operating systems and applications on a single physical machine.

### Debian vs Rocky
When comparing Rocky Linux and Debian, there are a few key differences to consider:

1. Rocky Linux is a new Linux distribution that was created in 2021 as a community-driven and open source alternative to CentOS. It is based on the source code of Red Hat Enterprise Linux (RHEL) and is intended for enterprise use.
2. Debian is a long-established Linux distribution that has been around since 1993. It is known for its stability, security, and flexibility, and is widely used as a server OS as well as a desktop OS.
3. Rocky Linux is based on RHEL, which means that it shares many of the same features and capabilities as RHEL. Debian, on the other hand, is an independent Linux distribution that has its own set of features and capabilities.

Ultimately, the choice between Rocky Linux and Debian will depend on your specific needs and requirements. If you have specific hardware or software requirements, or if you need a stable and reliable platform for enterprise use, Rocky Linux may be a good choice. If you are looking for a more flexible and customizable OS with a large repository of software packages, Debian may be a better fit.

### What is LVM(local volume manager)?
Logical Volume Manager (LVM) is a system for managing disk drives in a computer. It allows you to create and manage logical volumes, which are higher-level abstractions of disk space that can be easily resized and moved across physical disks.

LVM uses physical volumes (PVs) as the underlying storage for logical volumes (LVs). A PV can be a physical disk or a partition on a disk. You can create one or more LVs on top of a PV, and the LVs can be of different sizes and used for different purposes (e.g., as a root filesystem, a swap partition, or a data partition).

One of the main benefits of LVM is that it allows you to easily resize logical volumes without having to repartition the physical disks. This is useful if you need to change the size of a logical volume due to changing storage needs or if you want to move a logical volume to a different physical disk.

LVM is commonly used in Linux systems, but it is also available on other operating systems such as Solaris and HP-UX.

```
$ uname -a : Identify the operating system.
$ lsblk : Show the partitions.
```
## Apt vs Aptitude
**`apt`** and **`aptitude`** are both package management tools for Debian-based Linux distributions. Both tools allow you to install, remove, and update software packages on your system.

**`apt`** (Advanced Package Tool) is a command-line tool that is used to manage packages on Debian-based systems. It is the primary package management tool in Debian and its derivatives, including Ubuntu and Linux Mint.

**`aptitude`** is also a command-line tool for managing packages on Debian-based systems. It is similar to **`apt`**, but it has a text-based user interface that allows you to browse and install packages in a more user-friendly way.

In general, **`apt`** is faster and more lightweight than **`aptitude`**, but **`aptitude`** is more feature-rich and user-friendly. Both tools can be used to install, remove, and update packages on a Debian-based system, and they share a common package database, so the choice of which tool to use is mostly a matter of personal preference.

## AppArmor
### What is AppArmor?
AppArmor (Application Armor) is a Linux security module that allows an administrator to set fine-grained permissions for applications and processes. It is designed to protect the operating system and its users from malicious programs by restricting the programs' access to system resources.

AppArmor works by defining profiles for each application or process, which specify the resources that the program is allowed to access and the actions it is allowed to perform. These profiles are stored in plain text files and can be edited by an administrator to customize the permissions for each application. When an application is launched, AppArmor enforces the permissions defined in its profile, preventing the application from accessing or modifying resources outside of its allowed permissions.

AppArmor can be used to secure a wide range of applications, including web servers, databases, and network utilities. It is particularly useful for protecting against malware and other malicious software, as it can prevent these programs from accessing sensitive data or modifying system configurations.

Overall, AppArmor is a powerful tool for enhancing the security of a Linux system by limiting the actions of individual applications and processes.
```
$ sudo apparmor_status
$ sudo aa-enabled
```
## SSH & UFW
### What is SSH?
SSH (Secure Shell) is a network protocol that allows secure remote login and other secure network services to be used over an insecure network. It provides strong authentication and secure communications over unsecured channels by encrypting data transferred between client and server.

The most common use of SSH is to log in to a remote server, allowing users to access and control the server as if they were physically present at the computer. SSH can also be used to securely transfer files between computers, or to establish a secure connection to a network device such as a router or switch.

To use SSH, a client program (such as the OpenSSH client) is used to connect to an SSH server running on the remote machine. The client authenticates the server using public-key cryptography, and then the two systems establish an encrypted connection. Once the connection is established, the client can run commands on the server or transfer files between the two systems.  

Overall, SSH is an important tool for securely accessing and managing remote systems over an insecure network, and is widely used in network administration and other fields. 

### What is UFW?
UFW stands for "Uncomplicated Firewall." It is a command-line tool for configuring and managing a firewall on Ubuntu and Debian Linux systems. UFW is designed to be easy to use, and it provides a simple, command-line interface for controlling network traffic. It is a front-end for the iptables firewall, and it is the default firewall configuration tool on Ubuntu. With UFW, you can allow or deny incoming or outgoing traffic based on various criteria such as IP address, port number, or protocol. It also provides a set of commands to check the firewall status, rules and to add or delete rules.

### What is Port Forwarding?
Port forwarding is a technique used to allow incoming network connections to reach a specific device or service within a network. It is often used to allow access to servers or other devices that are running on a private network from the Internet.

To set up port forwarding, an administrator typically configures a router or other network device to listen for incoming connections on a specific port and to forward those connections to a specific device or service within the network. For example, an administrator might set up port forwarding to allow incoming connections to a web server running on a private network to be forwarded to the server's IP address and port.

To use port forwarding, a client on the Internet would send a request to the router's public IP address and the specified port. The router would then forward the request to the specified device or service within the network.

Overall, port forwarding is a useful technique for allowing access to devices and services running on a private network from the Internet. It is often used in combination with network address translation (NAT) to provide secure access to network resources.

### What is TCP?
TCP (Transmission Control Protocol) is a widely used network protocol that provides reliable, stream-oriented transmission of data between two devices over a network. It is a transport layer protocol that is used in conjunction with higher-level protocols such as HTTP, FTP, and Telnet to provide reliable data transmission.

TCP is designed to ensure that data is delivered to its destination without errors and in the correct order. It does this by using a number of mechanisms, including error checking, flow control, and retransmission of lost data.

To transmit data using TCP, a connection must be established between the two devices. Once the connection is established, data can be exchanged in the form of streams of bytes. The sender can transmit data at any time, and the receiver can read the data as it arrives.

TCP is widely used in many different types of networks, including the Internet. It is a reliable protocol that is well-suited for applications that require the accurate and efficient transmission of data.

Overall, TCP is an important network protocol that is used to provide reliable data transmission between devices over a network. It is a key component of many higher-level protocols and is essential for many types of communication and data transfer.

```
$ apt search openssh-server
$ systemctl status ssh
$ ss -tunpl
$ sudo systemctl restart ssh
$ sudo vi /etc/ssh/sshd_config

$ command -v ufw
$ sudo ufw status
$ sudo ufw enable
$ sudo ufw default deny

$ sudo ufw allow 4242
$ sudo ufw status numbered
$ sudo ufw delete [number]

$ ssh minju@192.168.56.1 -p 4242
$ logout
$ exit
```

## Hostname and partitions
```
$ hostnamectl
$ sudo hostnamectl set-hostname [hostname]
```

## User Management
```
$ sudo vi /etc/login.defs
$ sudo vi /etc/pam.d/common-password
$ dpkg -l | grep libpam-pwquality

$ sudo adduser [username]
$ getent passwd [username]
$ sudo chage -l [username]

$ sudo addgroup [groupname]
$ sudo adduser [username] [groupname]
$ usermod -aG [groupname1,groupname2, ... ] [username]
$ getent [groupname] [username] // Show the members of the [groupname]
$ groupdel [groupname]
$ groupmod -n [groupname] [new_groupname]
$ usermod -g [groupname] [username] // primary group
$ id [username] // Config the groups of user

$ sudo adduser [username]
$ sudo adduser [username] sudo
$ getent group sudo // Show the members of the sudo
$ passwd -e [username] :-e: // User password forced expiration

$ chage -m 2 -M 30 -W 7 [username]
// chage: A command to set or change the validity period of a user password for system security
```
### What is cron?
Cron is a time-based job scheduler in Unix-like operating systems. Users can schedule jobs (commands or scripts) to run automatically at a specified time or date. The scheduled jobs are known as "cron jobs." Cron reads the configuration file called crontab (cron tables) to determine which commands to execute and when. The configuration files are stored in the /etc/crontab file or in the /etc/cron.*/ directories.

```
$ sudo crontab -e : modify crontab
$ sudo crontab -l : Check
$ sudo service cron start
$ sudo service cron stop
```