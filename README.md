# Programming Challenges

##### 2022 Summer Programming Challenges Study

### Github action judge

- Edit `.github/workflows/judge.yml`

```
  matrix:
    set:
    - problem: {{problem_no}}
      code: {{relative_path_of_code}}
```

### Local judge

- Edit `judge.sh`

```
sh .judge/submit.sh {{problem_no}} {{relative_path_of_code}}
```
