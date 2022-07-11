# Programming Challenges

##### 2022 Summer Programming Challenges Study

### Book

![image](https://images-na.ssl-images-amazon.com/images/I/410wQRDnpwL._SX258_BO1,204,203,200_.jpg)

##### Programming Challenges: The Programming Contest Training Manual (Texts in Computer Science)

- [Online Judge](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=28)
- [PDF](http://acm.cs.buap.mx/downloads/Programming_Challenges.pdf)

### Github Action Judge

- Edit `.github/workflows/judge.yml`

```
  matrix:
    set:
    - problem: {{problem_no}}
      code: {{relative_path_of_code}}
```

### Local Judge

- Edit `judge.sh`

```
sh .judge/submit.sh {{problem_no}} {{relative_path_of_code}}
```
