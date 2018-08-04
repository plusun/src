This is the repository for the [GSoC](https://summerofcode.withgoogle.com/) 2018 project of 
"[Integrate libFuzzer With the Basesystem](https://summerofcode.withgoogle.com/projects/#6417656001855488)".

For more details about what I have done during GSoC 2018, you can refer to these articles:

- [GSoC 2018 Reports: Integrate libFuzzer with the Basesystem, Part 1](http://blog.netbsd.org/tnf/entry/gsoc_2018_reports_integrate_libfuzzer)
- [GSoC 2018 Reports: Integrate libFuzzer with the Basesystem, Part 2](http://blog.netbsd.org/tnf/entry/gsoc_2018_reports_integrate_libfuzzer1)

There are also other repositories/branches which are used during this project and below
is a brief introduction for all of them.


# [src](https://github.com/plusun/src/)
This repository is forked from the [NetBSD/src](https://github.com/NetBSD/src). The links for
the "Bug(s)" in the following lines are the potential bugs we have found during this project
with the help of libFuzzer.

#### [Branch gsoc2018](https://github.com/plusun/src/)
This branch is used for the LLVM porting and the fuzzing of basic libraries in the NetBSD source.

It contains the changes of:
- Porting LLVM (Commit: [I](https://github.com/plusun/src/commit/57ce7ee505381288e2c075f5bc24e454dcaa8774))
  - Test cases for MSan (Commits: [I](https://github.com/plusun/src/commit/78d5dfd33215508af3a8824c7ba1392d6ceacf8a), [II](https://github.com/plusun/src/commit/5d96c8f8e084f006824536bfd0622ee3788bc23c))
  - Test cases for TSan (Commit: [I](https://github.com/plusun/src/commit/5f537712dde1e4eb87b6022e371cd48393a4bb5e))
  - Test cases for libFuzzer ( Commit: [I](https://github.com/plusun/src/commit/ff6d9228c17140919df34c280e32823bcbf7ecf6))
- Fuzzing [regex(3)](http://netbsd.gw.com/cgi-bin/man-cgi?regex+3+NetBSD-current) functions
  - libc version (Commits: [I](https://github.com/plusun/src/commit/0d828a78c982fb2289b86ec619896bfda55c29d7), [II](https://github.com/plusun/src/commit/74bc15fcf31878278cb8f8281a1bbde843e6ae1c), [III](https://github.com/plusun/src/commit/f4653a2a658a7422f4ee4077906dcdb3e0448850), [IV](https://github.com/plusun/src/commit/5bb3dffd418d72ff018782ad0f056f82560bf0fb); Bug: [I](https://github.com/plusun/src/tree/gsoc2018/tests/fuzz/regex/libc/regexec/bug))
  - nvi version (Commits: [I](https://github.com/plusun/src/commit/336cc66b3cae2448d8a984a076d2ee921a946760), [II](https://github.com/plusun/src/commit/4b956b7fc9d8bfe95be7e9c876aa685615e1774c), [III](https://github.com/plusun/src/commit/99b455119b26377273ee2502f2fdd6adf702f6c0), [IV](https://github.com/plusun/src/commit/b49e95e9d3692f40fc3d75ec886fb3ffe7bc09f2), [V](https://github.com/plusun/src/commit/498b45c2c6da90004a78fa91383f09bbab503873), [VI](https://github.com/plusun/src/commit/dfa23d9c2d850998be1e2786527c39986efa514e), [VII](https://github.com/plusun/src/commit/cbf271e1340f301ead4b228c10848fba0e45afbe); Bug: [I](https://github.com/plusun/src/tree/gsoc2018/tests/fuzz/regex/nvi/regcomp/bug))
  - [grep(1)](http://netbsd.gw.com/cgi-bin/man-cgi?grep+1+NetBSD-current) version (Commits: [I](https://github.com/plusun/src/commit/0c239dc46ba2f536c76c3004e1cca3c7d0255ada), [II](https://github.com/plusun/src/commit/3256c321a71765ae23ca3caa1e6bf763de651901), [III](https://github.com/plusun/src/commit/f826dbbca7b610582506ca71ec62f58909f5a0b5); Bug: [I](https://github.com/plusun/src/tree/gsoc2018/tests/fuzz/regex/grep/regcomp/bug))
  - agrep version (Commits: [I](https://github.com/plusun/src/commit/3899801db97939780073ec9089b15d7f7c7ad389), [II](https://github.com/plusun/src/commit/3d6fd232d33c577d5e708d472ecfafa9643b8e1a), [III](https://github.com/plusun/src/commit/e22e4257cd8c4886ce81df54397278c27cc4480c), [IV](https://github.com/plusun/src/commit/9ac1010586bd05122316e41e70171ba295b3b8cf); Bug: [I](https://github.com/plusun/src/tree/gsoc2018/tests/fuzz/regex/agrep/regcomp/bug))
  - diffutils versoin (Commits: [I](https://github.com/plusun/src/commit/890b7da466dd07db729133e382522fc2e2dc74bd), [II](https://github.com/plusun/src/commit/e481c49978c4d346eae9b9d392576f1dc589eab7), [III](https://github.com/plusun/src/commit/c9c18a7670db622d4943520aee9ab5bcf4e81df2); Bug: [I](https://github.com/plusun/src/tree/gsoc2018/tests/fuzz/regex/diffutils/regcomp/bug))
  - xcvs version (Commits: [I](https://github.com/plusun/src/commit/331f44467b22f526adc5301ef66cbae97170a835), [II](https://github.com/plusun/src/commit/b3a3f41ee8d9a330fc16eda304c03f20d8e170ab), [III](https://github.com/plusun/src/commit/cf8bb22313d14bed6d33f795bf0e0c8e49c7b3c4), [IV](https://github.com/plusun/src/commit/6817666411ff0286415e4035c5c2ce09298f8a0d); Bug: [I](https://github.com/plusun/src/tree/gsoc2018/tests/fuzz/regex/xcvs/regcomp/bug))
- Fuzzing checksum functions
  - [md2(3)](http://netbsd.gw.com/cgi-bin/man-cgi?md2+3+NetBSD-current) (Commits: [I](https://github.com/plusun/src/commit/f98643efbf1a475a960607437cffaaf939f57148), [II](https://github.com/plusun/src/commit/487f7fbe9652b0b26a384a2421cae3dc545bef08), [III](https://github.com/plusun/src/commit/064728ed5889ec7188d6393066b9906faa8c604e), [IV](https://github.com/plusun/src/commit/a5dfb400ef57f878cdd618499648745b60a1a998))
  - [md4(3)](http://netbsd.gw.com/cgi-bin/man-cgi?md4+3+NetBSD-current) (Commits: [I](https://github.com/plusun/src/commit/9617b488df058c8a82fd2b1e32e188c7674b0e96), [II](https://github.com/plusun/src/commit/af63ca067a85ea8aec158121971f6fb5f6c6633e), [III](https://github.com/plusun/src/commit/bb2ad52244abf7035d2137eca29e8b222f9164c7), [IV](https://github.com/plusun/src/commit/fb3ea9960e762cb5ebdfcae784456ee81bb25980))
  - [md5(3)](http://netbsd.gw.com/cgi-bin/man-cgi?md5+3+NetBSD-current) (Commits: [I](https://github.com/plusun/src/commit/b1c448ccd690b81cb39b699443fd70796545e6f4), [II](https://github.com/plusun/src/commit/49f4eecb96b52f23c00b32a770eb06450edb438f), [III](https://github.com/plusun/src/commit/382ffc6c1d83c4ee48a60316e907dfff9efa57d8))
  - [rmd160(3)](http://netbsd.gw.com/cgi-bin/man-cgi?rmd160+3+NetBSD-current) (Commits: [I](https://github.com/plusun/src/commit/150bc7d0a246c01fafe6dda6d619b3a37bb764d6), [II](https://github.com/plusun/src/commit/5e5cf9a836a2a1281a8a84633b5b20d63d6484ae), [III](https://github.com/plusun/src/commit/55445f63232410d86b3d3fe1fd21d1ded6afe603))
  - [sha1(3)](http://netbsd.gw.com/cgi-bin/man-cgi?sha1+3+NetBSD-7.0) (Commits: [I](https://github.com/plusun/src/commit/ed13aee7f4c0e29971c4ab81772598c20cf70323), [II](https://github.com/plusun/src/commit/95f43f96cf0e8468e4fcec77da0861b6ff5dc0f6), [III](https://github.com/plusun/src/commit/da7b6c2befb84949284484309f53c52336a2d3bf))
  - crc
    - Kernel versoin (Commits: [I](https://github.com/plusun/src/commit/c7895218545c6c9c8f75dbb68b5bfb8969bc1026), [II](https://github.com/plusun/src/commit/04ebf91ddb2fc1de6cf93552d557b27495a6c24b), [III](https://github.com/plusun/src/commit/2cdabfc8bf16fcf7ae44e55f1d98fb48a91e1e62))
    - [cksum(1)](http://netbsd.gw.com/cgi-bin/man-cgi?cksum+1+NetBSD-current) version (Commits: [I](https://github.com/plusun/src/commit/4e58562badf5372da6cd0edc599282ee2b0929be), [II](https://github.com/plusun/src/commit/26a0a2972d5b5c8668c0115d0e81477d622bcceb))
- Fuzzing [libutil(3)](http://netbsd.gw.com/cgi-bin/man-cgi?libutil+3+NetBSD-current)
  - strspct (Commits: [I](https://github.com/plusun/src/commit/67d5e6f8b1d664615291a130f1d4c0af2f3f3247), [II](https://github.com/plusun/src/commit/169d088bc2ade00132e043f138b5112abcecdc40), [III](https://github.com/plusun/src/commit/5ef008a0ec55ccfc62e7c8264f673d6591a2abd1), [IV](https://github.com/plusun/src/commit/37e30c19869c83af99cf1a82d10242d3df0155a2); Bug: [I](https://github.com/plusun/src/tree/gsoc2018/tests/fuzz/libutil/strspct/bug))
  - getdiskcookedname (Commits: [I](https://github.com/plusun/src/commit/99fa066bf1c7fa40efccfc4e4a555a98c4e01328), [II](https://github.com/plusun/src/commit/19fee4bb64cb70f791df30ba798e0888aec1f24d))
  - logout (Commit: [I](https://github.com/plusun/src/commit/de460602fa09b0a0247fc42914b87a0cae15ecfa))
  - logoutx (Commit: [I](https://github.com/plusun/src/commit/92d97487b8ae3270fbcd8edfd2597e30ebb43f66))
  - pidfile_read (Commit: [I](https://github.com/plusun/src/commit/83a8d6fd2e080612634ebc362f6b228b8785068e))
  - secure_path (Commit: [I](https://github.com/plusun/src/commit/a976a33e0593b1bde3ade93a37bbc0c4fc91630d))
- Fuzzing [bozohttpd(8)](http://netbsd.gw.com/cgi-bin/man-cgi?bozohttpd+8+NetBSD-7.0) (Commits: [I](https://github.com/plusun/src/commit/192d68491d36660e73816e0df4adf9a907821667), [II](https://github.com/plusun/src/commit/312c8ee93bf2ed244ae915ed3fc42f65e9d8416b), [III](https://github.com/plusun/src/commit/a678877b72a8a9534b898eff909355a0068c4733), [IV](https://github.com/plusun/src/commit/538944520ea439d8830a3651ea68eacf601acdb6), [V](https://github.com/plusun/src/commit/2d883e060ea38f20bf59a95d65f7f7ca600ea0f0), [VI](https://github.com/plusun/src/commit/492f1d7621bfc190885a361c0e75d92c225d9e23); Bug: [I](https://github.com/plusun/src/tree/gsoc2018/tests/fuzz/bozohttpd/bozohttpd/bug))
- Fixing two bugs in [top(1)](http://netbsd.gw.com/cgi-bin/man-cgi?top+1.i386+NetBSD-7.1.2) (Commit: [I](https://github.com/plusun/src/commit/161607510d44ee407010783a02fd6a4a4e790e04))
  - This has been merged by the [NetBSD/src]() (Commits: [I](https://github.com/NetBSD/src/commit/0127224588b2392894a1860e3e4473b4d09737d9), [II](https://github.com/NetBSD/src/commit/773e262b99a13372328c120d05da59d810b38b35))

#### [Branch fuzzer-expr](https://github.com/plusun/src/tree/fuzzer-expr)
This branch is used for the aggressive implementation of fuzzing userland applications.
Here, the word "aggressive" means that these changes may either use tricky mechanisms
or need bulk modifications to the original implementations.

It contains the changes of:
- Fuzzing [expr(1)](http://netbsd.gw.com/cgi-bin/man-cgi?expr+1+NetBSD-current) (Commits: [I](https://github.com/plusun/src/commit/237d95ea82656f8d7a8a1e1ac3cea81f06505a5c), [II](https://github.com/plusun/src/commit/236316e980e653912d2bd3ea117b4db8ab473e09), [III](https://github.com/plusun/src/commit/5b6a912ba0adbffc40f2b382e98143ad17547a6b), [IV](https://github.com/plusun/src/commit/13025204c5d8117a9debae25507c00ed91798413), [V](https://github.com/plusun/src/commit/0de68641bd5453e615ed078731d820cadbcfbf4f), [VI](https://github.com/plusun/src/commit/cac87439bd786616765a3cbfe3157d3afc087a6c), [VII](https://github.com/plusun/src/commit/f97b43befa920b7ff517fedccf7f1564f7eb8937); Bugs: [I](https://github.com/plusun/src/commit/0978ffd444b1eee130469ba0757fc9c5eea20f11), [II](https://github.com/plusun/src/commit/2015b1736b8696f230cf3bd6d358627fb136caa1))
- Fuzzing [sed(1)](http://netbsd.gw.com/cgi-bin/man-cgi?sed++NetBSD-current) (Commits: [I](https://github.com/plusun/src/commit/7ffe9f0913bd5df467c3954e465b113baeec0478), [II](https://github.com/plusun/src/commit/7f7a5fe1ce8878c16038501a4f56d8034ee1b0f1), [III](https://github.com/plusun/src/commit/5813323167821b994472ed99452b5a941143c6b8))
- Fuzzing [sh(1)](http://netbsd.gw.com/cgi-bin/man-cgi/man?sh++NetBSD-5.0) (Commits: [I](https://github.com/plusun/src/commit/330d96ab65ab89588fc5b77a1e80c1dc56332630), [II](https://github.com/plusun/src/commit/3fe4285b1f502f03c8360bbb73c07176148f3980), [III](https://github.com/plusun/src/commit/61a2c9e582bb1e53e8f3948f42c44c5d015742a9), [IV](https://github.com/plusun/src/commit/2bf88393158ed18e7752eb32aadacccc1544d0c4), [V](https://github.com/plusun/src/commit/e522c4734ed3a3729017c933947ad57295c234e9), [VI](https://github.com/plusun/src/commit/9e8975e5b346f40dc34f3ef5a383e9e9a60275b6))
- Fuzzing [ping(8)](http://netbsd.gw.com/cgi-bin/man-cgi?ping+8+NetBSD-6.0+i386) (Commits: [I](https://github.com/plusun/src/commit/e1c3961309aee28627a8ad584f5d0de1b8594e62), [II](https://github.com/plusun/src/commit/2899dff446e040046b0b096ad733c806824aafb2), [III](https://github.com/plusun/src/commit/8bd62773df09a7cdd987cd0082ac8a940514e90c), [IV](https://github.com/plusun/src/commit/726e4f31a301e037163d2b9e05e54dd9bbd01dda), [V](https://github.com/plusun/src/commit/0652e35542ba8b7bdd3a1ce1252e6726a4eadd88), [VI](https://github.com/plusun/src/commit/f9c75acc55f053f3986c5f5d647e04eb0222a459), [VII](https://github.com/plusun/src/commit/ff93df23a0383502d7e8af8d9289d52569b9999b))

#### [Branch afl-hongg-expr](https://github.com/plusun/src/tree/afl-hongg-expr)
This branch provides the source for fuzzing applications with [AFL](http://lcamtuf.coredump.cx/afl/) and
[honggfuzz](https://github.com/google/honggfuzz) to make a comparison with the libFuzzer in the evaluation.

It only contains a part of the fuzzed programs, this is because other programs we have evaluated need no
modification to work them. Here is what this branch includes:
- Fuzzing [expr(1)](http://netbsd.gw.com/cgi-bin/man-cgi?expr+1+NetBSD-current) (Commit: [I](https://github.com/plusun/src/commit/14bd975209149352f8aea4ace6be70a18541afb8))
- Fuzzing [ping(8)](netbsd.gw.com/cgi-bin/man-cgi?ping+8+NetBSD-6.0+i386) (Commit: [I](https://github.com/plusun/src/commit/7adf30b6d2ec13449c1327468e44974162258b4f))

#### [Branch LD_PRELOAD](https://github.com/plusun/src/tree/LD_PRELOAD)
This branch includes the source of fuzzing ping(8) with honggfuzz without any modification to original
implementation. It is implemented with the help of HF_ITER interface provided by the honggfuzz and
LD_PRELOAD environment. Here are the commits: [I](https://github.com/plusun/src/commit/4c5e2d86a6d4453eefc264d5f55374973e5425a3), [II](https://github.com/plusun/src/commit/e1920ca6c6250bbc632446187ea5cc98a7c2c423), [III](https://github.com/plusun/src/commit/5c11886077794985eddf4531a08f340ee97b96c1), [IV](https://github.com/plusun/src/commit/eeca866c9cffd34f971ba6a0a3aee94e032b9518), [V](https://github.com/plusun/src/commit/60c885dd6cb59e77bd12602f8b5295f7e7d86599), [VI](https://github.com/plusun/src/commit/50c871c61c4ec84bcb7b72bf41ef5dd8783fc0ba), [VII](https://github.com/plusun/src/commit/5b673a763c36e008bb31beac9abb6b027931f47f).


# [LLVM](https://github.com/plusun/llvm)
Forked from [llvm-mirror/llvm](https://github.com/llvm-mirror/llvm). This repository mainly contains
the changes to adapt current LLVM source to be statically linkable on NetBSD. There are two main commits:
[I](https://github.com/plusun/llvm/commit/50276909bce4d0d89fbeaa40860de61b46f72af0),
[II](https://github.com/plusun/llvm/commit/d05b8fcfad739d116227e198be88baa5f8699383).


# [compiler-rt](https://github.com/plusun/compiler-rt)
Forked from [llvm-mirror/compiler-rt](https://github.com/llvm-mirror/compiler-rt). This repository mainly
contributes to the porting of sanitizers to the NetBSD by adding interceptors for some interfaces. It includes
interceptors for:
- [statvfs(2)](http://netbsd.gw.com/cgi-bin/man-cgi?statvfs+2+NetBSD-current) (Commit: [I](https://github.com/plusun/compiler-rt/commit/4de2507cd566b437c8421eab95b87034828e3d25))
- [mount(2)](http://netbsd.gw.com/cgi-bin/man-cgi?mount+2+NetBSD-current) (Commits: [I](https://github.com/plusun/compiler-rt/commit/76d0859d5e67d8b17ec259654b996921e99323e5), [II](https://github.com/plusun/compiler-rt/commit/488332eb9e433dcdcc4a35e6795a5bb2f5e54169))
- [fseek(3)](http://netbsd.gw.com/cgi-bin/man-cgi?fseek+3+NetBSD-7.0) (Commit: [I](https://github.com/plusun/compiler-rt/commit/6d466c20aaf4e8e1894daacb7d3dd9ce88b6086f))
- [cdbr(3)](http://netbsd.gw.com/cgi-bin/man-cgi?cdbr+3+NetBSD-current) (Commit: [I](https://github.com/plusun/compiler-rt/commit/08bca30852bbd09d49b7cb32f903885b76ca9d16))
- [rmd160(3)](http://netbsd.gw.com/cgi-bin/man-cgi?rmd160+3+NetBSD-6.0) (Commit: [I](https://github.com/plusun/compiler-rt/commit/d095434de3babb5aae4ec16e1ac0bae815e7f5f7))
- [sha2(3)](http://netbsd.gw.com/cgi-bin/man-cgi?sha2+3+NetBSD-7.0) (Commit: [I](https://github.com/plusun/compiler-rt/commit/c8f480dcdae15736ad04c0f4b4aad1d702f157ae))
- [getchar(3)](http://netbsd.gw.com/cgi-bin/man-cgi?getchar+3+NetBSD-current) (Commit: [I](https://github.com/plusun/compiler-rt/commit/b33125fe5df40556082eaba922c8b2c1e78df233))
- [setvbuf(3)](http://netbsd.gw.com/cgi-bin/man-cgi?setvbuf+3+NetBSD-current) (Commit: [I](https://github.com/plusun/compiler-rt/commit/32fedd0bbc5f626018b3ca1b347ad4a1ab29289b))
- [mi_vector_hash(3)](http://netbsd.gw.com/cgi-bin/man-cgi?mi_vector_hash+3+NetBSD-6.0) (Commit: [I](https://github.com/plusun/compiler-rt/commit/38c8ba25ba93312b2e16e6871cfa28f69a58f7a1))
- Some other [24 commits](https://github.com/plusun/compiler-rt/pull/1/commits).


# [pkgsrc-wip](https://github.com/plusun/pkgsrc-wip)
This repository is forked from [NetBSD/pkgsrc-wip](https://github.com/NetBSD/pkgsrc-wip). The main
changes are two:
- Some scripts to work with libFuzzer, AFL and honggfuzz ([link](https://github.com/plusun/pkgsrc-wip/tree/gsoc2018/compiler-rt-netbsd))
  - Scripts for fuzzing applications with AFL and honggfuzz: [expr(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/afl-hongg-fuzz-expr.sh), [file(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/afl-hongg-fuzz-file.sh), [ping(8)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/afl-hongg-fuzz-ping.sh), [sed(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/afl-hongg-fuzz-sed.sh), [sh(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/afl-hongg-fuzz-sh.sh) and [some common lines](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/afl-honggfuzz-header.sh)
  - Script to build the whole NetBSD environment (inlcuding the LLVM tools): [link](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/build-all.sh)
  - Scripts to build single application/library under the NetBSD source tree
    - [Script](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/build-one.sh) to build with/without sanitizers
    - [Script](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/build-one-fuzzer.sh) to build with libFuzzer
    - [Script](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/build-one-afl-honggfuzz.sh) to build with AFL/honggfuzz
  - [Script](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/fuzz-microbenchmark.sh) to build microbenchmarks with different fuzzers
  - [Scripts] to fuzz applications with libFuzzer: [expr(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/fuzz_expr.sh), [ping(8)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/fuzz_ping.sh), [sed(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/fuzz_sed.sh), [sh(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/fuzz_sh.sh) and some [common lines](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/fuzzer_header.sh)
  - [Scripts] to fuzz applications with [Radamsa](https://github.com/aoh/radamsa): [expr(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/radamsa-fuzz-expr.sh), [file(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/radamsa-fuzz-file.sh), [sed(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/radamsa-fuzz-sed.sh), [sh(1)](https://github.com/plusun/pkgsrc-wip/blob/gsoc2018/compiler-rt-netbsd/radamsa-fuzz-sh.sh)
- Newly added honggfuzz package ([link](https://github.com/plusun/pkgsrc-wip/tree/gsoc2018/honggfuzz)). This package has been merged ([link](https://github.com/NetBSD/pkgsrc-wip/tree/master/honggfuzz)). There are also some changes which have been merged by the [google/honggfuzz](https://github.com/google/honggfuzz) to adapt honggfuzz to the NetBSD environment: in this [pull request](https://github.com/google/honggfuzz/pull/212).


# Other Contribution
- Fixed two non-standard usages of sem_open in the libFuzzer library and one NetBSD-related modification with test script. This has been merged by the LLVM community: [D46622](https://reviews.llvm.org/D46622).
