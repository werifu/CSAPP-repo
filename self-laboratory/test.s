
a.out：     文件格式 elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 e2 2f 00 00    	pushq  0x2fe2(%rip)        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmpq   *0x2fe4(%rip)        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <__stack_chk_fail@plt>:
    1030:	ff 25 e2 2f 00 00    	jmpq   *0x2fe2(%rip)        # 4018 <__stack_chk_fail@GLIBC_2.4>
    1036:	68 00 00 00 00       	pushq  $0x0
    103b:	e9 e0 ff ff ff       	jmpq   1020 <.plt>

0000000000001040 <printf@plt>:
    1040:	ff 25 da 2f 00 00    	jmpq   *0x2fda(%rip)        # 4020 <printf@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	pushq  $0x1
    104b:	e9 d0 ff ff ff       	jmpq   1020 <.plt>

Disassembly of section .text:

0000000000001050 <_start>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	31 ed                	xor    %ebp,%ebp
    1056:	49 89 d1             	mov    %rdx,%r9
    1059:	5e                   	pop    %rsi
    105a:	48 89 e2             	mov    %rsp,%rdx
    105d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1061:	50                   	push   %rax
    1062:	54                   	push   %rsp
    1063:	4c 8d 05 c6 01 00 00 	lea    0x1c6(%rip),%r8        # 1230 <__libc_csu_fini>
    106a:	48 8d 0d 4f 01 00 00 	lea    0x14f(%rip),%rcx        # 11c0 <__libc_csu_init>
    1071:	48 8d 3d d6 00 00 00 	lea    0xd6(%rip),%rdi        # 114e <main>
    1078:	ff 15 62 2f 00 00    	callq  *0x2f62(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    107e:	f4                   	hlt    
    107f:	90                   	nop

0000000000001080 <deregister_tm_clones>:
    1080:	48 8d 3d b1 2f 00 00 	lea    0x2fb1(%rip),%rdi        # 4038 <__TMC_END__>
    1087:	48 8d 05 aa 2f 00 00 	lea    0x2faa(%rip),%rax        # 4038 <__TMC_END__>
    108e:	48 39 f8             	cmp    %rdi,%rax
    1091:	74 15                	je     10a8 <deregister_tm_clones+0x28>
    1093:	48 8b 05 3e 2f 00 00 	mov    0x2f3e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    109a:	48 85 c0             	test   %rax,%rax
    109d:	74 09                	je     10a8 <deregister_tm_clones+0x28>
    109f:	ff e0                	jmpq   *%rax
    10a1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10a8:	c3                   	retq   
    10a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010b0 <register_tm_clones>:
    10b0:	48 8d 3d 81 2f 00 00 	lea    0x2f81(%rip),%rdi        # 4038 <__TMC_END__>
    10b7:	48 8d 35 7a 2f 00 00 	lea    0x2f7a(%rip),%rsi        # 4038 <__TMC_END__>
    10be:	48 29 fe             	sub    %rdi,%rsi
    10c1:	48 89 f0             	mov    %rsi,%rax
    10c4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10c8:	48 c1 f8 03          	sar    $0x3,%rax
    10cc:	48 01 c6             	add    %rax,%rsi
    10cf:	48 d1 fe             	sar    %rsi
    10d2:	74 14                	je     10e8 <register_tm_clones+0x38>
    10d4:	48 8b 05 15 2f 00 00 	mov    0x2f15(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    10db:	48 85 c0             	test   %rax,%rax
    10de:	74 08                	je     10e8 <register_tm_clones+0x38>
    10e0:	ff e0                	jmpq   *%rax
    10e2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10e8:	c3                   	retq   
    10e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010f0 <__do_global_dtors_aux>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	80 3d 3d 2f 00 00 00 	cmpb   $0x0,0x2f3d(%rip)        # 4038 <__TMC_END__>
    10fb:	75 33                	jne    1130 <__do_global_dtors_aux+0x40>
    10fd:	55                   	push   %rbp
    10fe:	48 83 3d f2 2e 00 00 	cmpq   $0x0,0x2ef2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1105:	00 
    1106:	48 89 e5             	mov    %rsp,%rbp
    1109:	74 0d                	je     1118 <__do_global_dtors_aux+0x28>
    110b:	48 8b 3d 1e 2f 00 00 	mov    0x2f1e(%rip),%rdi        # 4030 <__dso_handle>
    1112:	ff 15 e0 2e 00 00    	callq  *0x2ee0(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1118:	e8 63 ff ff ff       	callq  1080 <deregister_tm_clones>
    111d:	c6 05 14 2f 00 00 01 	movb   $0x1,0x2f14(%rip)        # 4038 <__TMC_END__>
    1124:	5d                   	pop    %rbp
    1125:	c3                   	retq   
    1126:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    112d:	00 00 00 
    1130:	c3                   	retq   
    1131:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1138:	00 00 00 00 
    113c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001140 <frame_dummy>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	e9 67 ff ff ff       	jmpq   10b0 <register_tm_clones>

0000000000001149 <f>:
    1149:	0f b6 47 01          	movzbl 0x1(%rdi),%eax
    114d:	c3                   	retq   

000000000000114e <main>:
    114e:	48 83 ec 28          	sub    $0x28,%rsp
    1152:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1159:	00 00 
    115b:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    1160:	31 c0                	xor    %eax,%eax
    1162:	48 b8 74 65 73 74 20 	movabs $0x7274732074736574,%rax
    1169:	73 74 72 
    116c:	ba 69 6e 67 0a       	mov    $0xa676e69,%edx
    1171:	48 89 04 24          	mov    %rax,(%rsp)
    1175:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
    117a:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%rsp)
    1181:	00 
    1182:	48 89 e7             	mov    %rsp,%rdi
    1185:	e8 bf ff ff ff       	callq  1149 <f>
    118a:	0f be f0             	movsbl %al,%esi
    118d:	48 8d 3d 70 0e 00 00 	lea    0xe70(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    1194:	b8 00 00 00 00       	mov    $0x0,%eax
    1199:	e8 a2 fe ff ff       	callq  1040 <printf@plt>
    119e:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    11a3:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    11aa:	00 00 
    11ac:	75 0a                	jne    11b8 <main+0x6a>
    11ae:	b8 00 00 00 00       	mov    $0x0,%eax
    11b3:	48 83 c4 28          	add    $0x28,%rsp
    11b7:	c3                   	retq   
    11b8:	e8 73 fe ff ff       	callq  1030 <__stack_chk_fail@plt>
    11bd:	0f 1f 00             	nopl   (%rax)

00000000000011c0 <__libc_csu_init>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	41 57                	push   %r15
    11c6:	4c 8d 3d 1b 2c 00 00 	lea    0x2c1b(%rip),%r15        # 3de8 <__frame_dummy_init_array_entry>
    11cd:	41 56                	push   %r14
    11cf:	49 89 d6             	mov    %rdx,%r14
    11d2:	41 55                	push   %r13
    11d4:	49 89 f5             	mov    %rsi,%r13
    11d7:	41 54                	push   %r12
    11d9:	41 89 fc             	mov    %edi,%r12d
    11dc:	55                   	push   %rbp
    11dd:	48 8d 2d 0c 2c 00 00 	lea    0x2c0c(%rip),%rbp        # 3df0 <__do_global_dtors_aux_fini_array_entry>
    11e4:	53                   	push   %rbx
    11e5:	4c 29 fd             	sub    %r15,%rbp
    11e8:	48 83 ec 08          	sub    $0x8,%rsp
    11ec:	e8 0f fe ff ff       	callq  1000 <_init>
    11f1:	48 c1 fd 03          	sar    $0x3,%rbp
    11f5:	74 1f                	je     1216 <__libc_csu_init+0x56>
    11f7:	31 db                	xor    %ebx,%ebx
    11f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1200:	4c 89 f2             	mov    %r14,%rdx
    1203:	4c 89 ee             	mov    %r13,%rsi
    1206:	44 89 e7             	mov    %r12d,%edi
    1209:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    120d:	48 83 c3 01          	add    $0x1,%rbx
    1211:	48 39 dd             	cmp    %rbx,%rbp
    1214:	75 ea                	jne    1200 <__libc_csu_init+0x40>
    1216:	48 83 c4 08          	add    $0x8,%rsp
    121a:	5b                   	pop    %rbx
    121b:	5d                   	pop    %rbp
    121c:	41 5c                	pop    %r12
    121e:	41 5d                	pop    %r13
    1220:	41 5e                	pop    %r14
    1222:	41 5f                	pop    %r15
    1224:	c3                   	retq   
    1225:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    122c:	00 00 00 00 

0000000000001230 <__libc_csu_fini>:
    1230:	f3 0f 1e fa          	endbr64 
    1234:	c3                   	retq   

Disassembly of section .fini:

0000000000001238 <_fini>:
    1238:	f3 0f 1e fa          	endbr64 
    123c:	48 83 ec 08          	sub    $0x8,%rsp
    1240:	48 83 c4 08          	add    $0x8,%rsp
    1244:	c3                   	retq   
