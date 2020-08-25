# Without SELinux

## User/Group/Others - Read/Write/Execute

chown, chmod,

chown [-R] user:group file

chmod [-R] [ugo][+-=][rwx] file

## ACL - easy way to fine tune access

setfacl -m [ugw]:user:rwx file

getfacl -d file


## Extended Attributes (security.selinux - this is where SELinux label is stored)

setfattr -n user.var -v value file

getfattr -m . -d file

man xattr

# SELinux

## Enable

vi /etc/selinux/config <- set permissive

touch /.autorelabel

reboot

vi /etc/selinux/config <- set enforcing

getenforce / setenfore 1

sestatus

## Files

/etc/selinux/targeted/policy/policy.31 - policy file

/etc/selinux/targeted/contexts/files/file_contexts - file context golden source

# Set context commands

chcon

restorecon

## Information commands

semodule -l

seinfo [-c|-t|-b|-r] - classes / types / booleans / roles

semanage [boolean|user|login|port|fcontext] -l

getsebool -a

## Study Policy

sesearch -s source_type -t target_type -p permission -b boolean --allow

## Study policy source 

Get code: https://github.com/SELinuxProject/refpolicy

Study: policy/modules/services/apache.[te|fc|if]

## Configuration commands

semanage

setsebool

e.g.: semanage port -a -t http_port_t -p tcp $PORT

# Troubleshoot

journalctl -xe

ausearch

audit2allow

audit2why

# Docs:

## Wikis:

https://github.com/SELinuxProject/selinux-notebook/blob/main/src/toc.md

https://wiki.gentoo.org/wiki/SELinux

## Tutorials

https://www.digitalocean.com/community/tutorials/an-introduction-to-selinux-on-centos-7-part-1-basic-concepts

https://opensource.com/article/18/7/sysadmin-guide-selinux

## Repos

https://github.com/sjvermeu/small.coding

