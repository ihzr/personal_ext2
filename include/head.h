/*各个函数的声明*/

#ifndef HEAD_H
#define HEAD_H

/*../disk_drive.c*/
/*获取磁盘block数据块，int为block的编号，指针指向数据存放的位置，返回读取的字节数*/
int get_block_data(unsigned int,void *);
/*向block中写入数据，int为block的编号，指针指向数据存放的位置，返回写入的字节数*/
int write_block_data(unsigned int,const void *);
/*取ext2_inode中的数据，index为ext2_inode的磁盘编号,放入内存i节点m_inode中*/
int get_inode_data(int index, struct inode *m_inode);
/*向inode中写入数据，index为inode的磁盘编号，从内存i节点m_inode中读取*/
int write_inode_data(int index, struct inode *m_inode);

/*../bitmap.c*/
/*取block中的数据，读取放到ext2_super_block结构体指针指向的空间中*/
int get_superblock_data(struct ext2_super_block * sb);
/*向磁盘写入super_block数据*/
int write_superblock_data(struct ext2_super_block * sb);
/*根据磁盘物理块号，释放该块，并置数据位图相应位置为0，成功则返回1,失败返回-1*/
int free_block(int block_num);
/*在磁盘上申请新块，并置位图数据位图相应位为1，成功返回块号,不成功返回-1*/
int new_block();
/*释放相应的inode节点,成功返回1,失败返回-1*/
int free_inode(int inode_num);
/*申请新的inode节点，成功则返回i节点号,失败返回-1*/
int new_inode();
/*获得和写回磁盘上的节点位图块，主要供以上4个函数使用,成功返回1,失败返回-1*/
int get_inodemap(char *m_inodemap,int size);
int put_inodemap(char *m_inodemap,int size);

/*获得和写回磁盘上的数据位图块，主要供以上4个函数使用,成功返回1,失败返回-1*/
int get_blockmap(char *m_blockmap,int size);
int put_blockmap(char *m_blockmap,int size);


extern unsigned int  m_inodemap[256];
extern unsigned int  m_blockmap[256];
extern struct ext2_super_block sb;

#endif
