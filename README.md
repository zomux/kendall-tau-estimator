Kendall's Tau Estimator
=====================


Estimate Kendall's Tau on a alignment file for evaluate reordering results for Statistical Machine Translation systems.

How to build
---

```bash
cmake CMakeLists.txt
make
```

How to use
---

```bash
zcat src-ref.A3.final.gz | ./average_tau
```
