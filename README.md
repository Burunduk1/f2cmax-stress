# f2cmax-stress

Здесь вы найдёте решения, тесты, ссылки о ***задаче о двух станках***.

Описание задачи и частичное доказательство решения можно изучить 
на [e-maxx](http://e-maxx.ru/algo/johnson_problem_2)
или в [итмо-конспектах](https://neerc.ifmo.ru/wiki/index.php?title=F2Cmax)

Реализации решения данные и там, и там мне кажутся странными. Моя: <code>f2cmax_sk.cpp</code>

Кроме того на [codeforces](http://codeforces.com/blog/entry/14056) уже давно писали плохое про версию с компаратором

```cpp
less = [&]( int i, int j ){ return min(a[i], b[j]) < min(a[j], b[i]); };
```

В честь этого <code>f2cmax_sk_stress.cpp</code> и <code>result.txt</code> содержат тесты для сортировок <code>std::sort</code>, 
<code>bubbleSort</code>, <code>std::stable_sort</code>, позволяют добавлять собственные.
