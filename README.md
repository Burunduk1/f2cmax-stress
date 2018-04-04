# f2cmax-stress

Здесь вы найдёте решения, тесты, ссылки о задаче о двух станках.

Описание задачи и частичное доказательво решения можно изучить 
на [e-maxx](http://e-maxx.ru/algo/johnson_problem_2)
или в [итмо-конспектах](https://neerc.ifmo.ru/wiki/index.php?title=F2Cmax)

Реализация решения, данная там мне кажется странной. Моя: f2cmax_sk.cpp

Кроме того про версию с компаратором

```cpp
less = [&]( int i, int j ){ return min(a[i], b[j]) < min(a[j], b[i]); };
```

на [codeforces](http://codeforces.com/blog/entry/14056) давно писали плохое.
В честь этого f2cmax_sk_stress.cpp и result.txt содержат тесты для сортировок std::sort, bubbleSort, std::stable_sort, 
позволяют добавлять собственные.
