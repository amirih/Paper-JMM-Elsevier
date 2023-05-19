# Paper-JMM-Elsevier

Hossein Amiri, Asadollah Shahbahrami, Angela Pohl, Ben Juurlink,
Performance evaluation of implicit and explicit SIMDization,
Microprocessors and Microsystems,
Volume 63,
2018,
Pages 158-168,
ISSN 0141-9331,
https://doi.org/10.1016/j.micpro.2018.09.002.
(https://www.sciencedirect.com/science/article/pii/S0141933117304970)

Abstract: Processor vendors have been expanding Single Instruction Multiple Data (SIMD) extensions to exploit data-level-parallelism in their General Purpose Processors (GPPs). Each SIMD technology such as Streaming SIMD Extensions (SSE) and Advanced Vector eXtensions (AVX) has its own Instruction Set Architecture (ISA) which equipped with Special Purpose Instructions (SPIs). In order to exploit these features, many programming approaches have been developed. Intrinsic Programming Model (IPM) is a low-level concept for explicit SIMDization. Besides, Compiler’s Automatic Vectorization (CAV) has been embedded in modern compilers such as Intel C++ compiler (ICC), GNU Compiler Collections (GCC) and LLVM for implicit vectorization. Each SIMDization shows different improvements because of different SIMD ISAs, vector register width, and programming approaches. Our goal in this paper is to evaluate the performance of explicit and implicit vectorization. Our experimental results show that the behavior of explicit vectorization on different compilers is almost the same compared to implicit vectorization. IPM improves the performance more than CAVs. In general, ICC and GCC compilers can more efficiently vectorize kernels and use SPI compared to LLVM. In addition, AVX2 technology is more useful for small matrices and compute-intensive kernels compared to large matrices and data-intensive kernels because of memory bottlenecks. Furthermore, CAVs fail to vectorize kernels which have overlapping and non-consecutive memory access patterns. The way of implementation of a kernel impacts the vectorization. In order to understand what kind of scalar implementations of an algorithm is suitable for vectorization, an approach based on code modification technique is proposed. Our experimental results show that scalar implementations that have either loop collapsing, loop unrolling, software pipelining, or loop exchange techniques can be efficiently vectorized compared to straightforward implementations.
Keywords: Advanced Vector Extensions (AVX); Compiler; Intel; Intrinsic; SIMDization; Vectorization
### Warning:
* These codes are not cleaned to eliminate functions overhead and others.
* What do I mean about cleaned code? -> a maintainable code, an easy-to-read code, reviewable code.
