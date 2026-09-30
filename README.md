# Technology Olympics 2026 - Algorithm Track

![C++](https://img.shields.io/badge/Language-C%2B%2B20-00599C?logo=c%2B%2B)
![Platform](https://img.shields.io/badge/Platform-Quera%20%2F%20CodeRN-blue)
![Contest](https://img.shields.io/badge/Contest-Pardis%20Tech%20Olympics%202026-orange)
![Team](https://img.shields.io/badge/Team-stdc%2B%2B.h-success)
![License](https://img.shields.io/badge/License-MIT-green.svg)

Official solutions and algorithmic writeups for the **Pardis Technology Olympics 2026 (Algorithm Track)**, developed by team **`stdc++.h`** (**Amin Madani** & **Mohammad Davoudi**).

---

## 🏆 Summary of Problems

| # | Problem | Topic / Technique | Time Complexity | Space Complexity | Status |
|---|---|---|---|---|---|
| **Q1** | [Shootball](q1.cpp) | Simulation / Weighted Comparison | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | ✅ Accepted |
| **Q2** | [Chalan Choolan](q2.cpp) | Prefix & Suffix Walk / Monotonicity | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ | ✅ Accepted |
| **Q3** | [Headphone](q3.cpp) | Greedy / Closed-Form Math | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | ✅ Accepted |
| **Q4** | [Fishes](q4.cpp) | Prefix Sums / Binary Merge Reachability | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ | ✅ Accepted |
| **Q5** | [Lottery](q5.cpp) | Markov Automaton / Polynomial Matrix Exponentiation / Stirling Numbers | $\mathcal{O}(K^2 \log N)$ | $\mathcal{O}(K)$ | ✅ Solved |
| **Q6** | [Boloury](q6.cpp) | Dynamic Programming / Convex Hull Trick (CHT) | $\mathcal{O}(N \log N)$ | $\mathcal{O}(N)$ | ✅ Accepted |

---

## 🧠 Algorithmic Approaches

### Problem 1: Shootball ([`q1.cpp`](q1.cpp))
* **Concept:** Direct simulation of scores.
* Evaluates weighted score polynomials $x = a_1 + 2a_2 + a_3$, $y = b_1 + 2b_2 + b_3$, and $z = c_1 + 2c_2 + c_3$.
* Outputs the index of the competitor achieving the maximal weighted total.

### Problem 2: Chalan Choolan ([`q2.cpp`](q2.cpp))
* **Concept:** Bidirectional strictly decreasing walk bounds.
* Computes left-to-right strictly decreasing sequence lengths $L[i]$ and right-to-left strictly decreasing sequence lengths $R[i]$.
* For each position, the maximum valid detour is determined by $\min(L[i], R[i])$ when both directions are accessible, or $\max(L[i], R[i])$ otherwise.

### Problem 3: Headphone ([`q3.cpp`](q3.cpp))
* **Concept:** Convex stage partitioning & quadratic cost minimization.
* Analyzes the optimal step allocation across capacity blocks of size $2H$ with baseline offset $H + C$.
* Derived an exact $\mathcal{O}(1)$ closed-form formula without iterative search:
  $$\text{Ans} = (H + C)^2 + \left\lfloor \frac{\text{rem}}{2H} \right\rfloor \cdot H^2 + \left\lfloor \frac{\text{rem} \pmod{2H}}{2} \right\rfloor^2$$

### Problem 4: Fishes ([`q4.cpp`](q4.cpp))
* **Concept:** Adversarial prefix absorption vs. power-of-two suffix merges.
* At step $i$, fish 1 has consumed a prefix of weight $a[i-1]$. In the remaining suffix, adjacent fishes can merge at most $2^{i-1}$ or $2^{i-2}$ units.
* By inspecting the critical power-of-two interval boundaries and determining turn-order precedence, the minimum viable initial weight is found in a single linear pass.

### Problem 5: Lottery ([`q5.cpp`](q5.cpp))
* **Concept:** Generating functions, Markov automaton, and polynomial matrix exponentiation.
* Models the generation of subsequences from strings in $\{1, 2, 3\}^n$ via a 4-state finite automaton (representing the last chosen digit: $\emptyset, 1, 2, 3$).
* State transitions that produce an ascent ($1 \to 2$, $1 \to 3$, $2 \to 3$) are weighted by $(1 + x)$.
* Computes the $N$-th power of the $4 \times 4$ polynomial transition matrix modulo $x^{K+1}$ using binary matrix exponentiation in $\mathcal{O}(K^2 \log N)$.
* Converts the binomial moments to raw $K$-th moments $\mathbb{E}[G^K]$ via Stirling numbers of the second kind:
  $$\mathbb{E}[G^K] = \sum_{j=0}^K S(K, j) \cdot j! \cdot [x^j] P_N(x)$$

### Problem 6: Boloury ([`q6.cpp`](q6.cpp))
* **Concept:** Dynamic programming optimized with Monotonic Convex Hull Trick.
* Reformulates the total displacement cost into finding optimal partition points for sorted boundary elements:
  $$dp[i] = M + (i - 1) a_i + \min_{j < i} \left( -j \cdot a_i + dp[j] \right)$$
* Maintains the lower convex hull of lines $y = m_j \cdot x + c_j$ using a monotonic deque with integer cross-multiplication, achieving $\mathcal{O}(N)$ amortized DP execution time.

---

## 🛠️ Build and Execution

To compile any solution using GCC with standard optimizations:

```bash
# Compile with C++20 and O3 optimizations
g++ -O3 -std=c++20 q6.cpp -o q6

# Run against sample input
./q6 < input.txt
```

---

## 👥 Authors

* **Amin Madani** ([@aminmadaniofficial](https://github.com/aminmadaniofficial))
* **Mohammad Davoudi** ([@MDavoudi2011](https://github.com/MDavoudi2011))

*Team **`stdc++.h`** — Pardis Technology Olympics 2026*
