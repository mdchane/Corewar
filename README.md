* Corewar

** Virtual Machine

*** compiled champion organisation

| start address |          length | utility            |
|---------------+-----------------+--------------------|
| 0 =0x0000=    |               4 | magic number       |
| 4 =0x0004=    |             128 | champion's name    |
| 132 =0x0084=  |               4 | /unused/           |
| 136 =0x0088=  |               4 | champion' size     |
| 140 =0x008C=  |            2048 | champion's comment |
| 2188 =0x088C= |               4 | /unused/           |
| 2192 =0x0890= | champion's size | champion's code    |

*** assembly language instructions

| instructions | op codes | arguments                | purpose                                                                                                                                                                                                                       | cycles | modify carry | pre-load opcode |
|--------------+----------+--------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+--------+--------------+-----------------|
| =live=       | =0x01=   | player name over 4 bytes | say that the player is alive                                                                                                                                                                                                  |     10 | ✗            | ✓               |
| =ld=         | =0x02=   | 1 address + 1 register   | load =REG_SIZE= bytes from address to register                                                                                                                                                                                |      5 | ✓            | ✓               |
| =st=         | =0x03=   | 1 register + 1 address   | store =REG_SIZE= bytes from register to address                                                                                                                                                                               |      5 | ✗            | ✓               |
| =add=        | =0x04=   | 3 registers              | adds the contents of the 2 first and stores the result in the third                                                                                                                                                           |     10 | ✓            | ✓               |
| =sub=        | =0x05=   | 3 registers              | substracts the contents of the 2 first and stores the result in the third                                                                                                                                                     |     10 | ✓            | ✓               |
| =and=        | =0x06=   | 2 values + 1 register    | does a logic AND with the 2 firsts values and stores it in the register                                                                                                                                                       |      6 | ✓            | ✓               |
| =or=         | =0x07=   | 2 values + 1 register    | does a logic OR with the 2 firsts values and stores it in the register                                                                                                                                                        |      6 | ✓            | ✓               |
| =xor=        | =0x08=   | 2 values + 1 register    | does a logic XOR with the 2 firsts values and stores it in the register                                                                                                                                                       |      6 | ✓            | ✓               |
| =zjump=      | =0x09=   | 1 index                  | if carry == 1, store (PC + (arg % IDX_MOD)) in PC                                                                                                                                                                             |     20 | ✗            | ✓               |
| =ldi=        | =0x0a=   | 2 indexes + 1 register   | ldi 3,%4,r1 reads IND_SIZE bytes at address: (PC + (3 % IDX_MOD)), adds 4 to this value. We will name this sum S. Read REG_SIZE bytes at address (PC + (S % IDX_MOD)), which are copied to r1. Parameters 1 and 2 are indexes |     25 | ✗            | ✓               |
| =sti=        | =0x0b=   |                          |                                                                                                                                                                                                                               |     25 | ✗            | ✓               |
| =fork=       | =0x0c=   |                          |                                                                                                                                                                                                                               |    800 | ✗            | ✓               |
| =lld=        | =0x0d=   |                          |                                                                                                                                                                                                                               |     10 | ✗            | ✓               |
| =lldi=       | =0x0e=   |                          |                                                                                                                                                                                                                               |     50 | ✗            | ✓               |
| =lfork=      | =0x0f=   |                          |                                                                                                                                                                                                                               |   1000 | ✗            | ✓               |
| =aff=        | =0x10=   |                          |                                                                                                                                                                                                                               |      2 | ✓            | ✓ 	           |

