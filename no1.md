# ssh 免密登录设置:

1. 在本地执行ssh-keygen -t rsa 生成本机公钥文件
2. ssh-copy_id ada@192.168.30.129 将本机公钥内容拷贝到远程.ssh文件夹下的authorized_keys文件内。需要注意：.ssh文件夹和autoorized_keys文件权限要保持700权限。权限不对不能免密登录。
3. 执行ssh即可验证是否可以无密码登录。
