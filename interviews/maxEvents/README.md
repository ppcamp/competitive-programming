TODO: add description and visualization for this algorithm


Base principle: optimization problem, aiming to find the optimum solution
locally, expecting that this will be the best solution globally.

Example:

given `N` types of coins (in this case, 5): `[25, 10, 4, 3, 1]`,
how can we achieve 60 coins, with less number of it:

We can create a greedy algorithm, that will try to take the most significant
one and try to use it, thus `[25,25,10]`

but if we, using same algorithm, to achieve 6 coins, it'll be: `[4,1,1]`, this
is the **local optimal** solution, but we know that the *best* **global solution**
will be `[3,3]`. Therefore, the suggestted algorithm is a greedy one
and it's considered as this, due to its aspect of indicating a "good solution"
but not necessarily the best one.

Notice that if we do all combinations, and run one by one, we'll find the best
global one, but what if we increase the number of coins available in such a way
that it gets way too much combination (several possibilities), making it
impossible to get the output in a reasonable time.