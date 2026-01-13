# Contributing to `fiber-audio-tx`

This document explains how we work together on this repo.

The goals:

- `main` is always buildable and ready for demos.
- Work is done in small, focused branches.
- Every change is reviewed by at least one other person.

---

## 1. Prerequisites

Before contributing, you should have:

- A GitHub account, added as a collaborator on the repo.
- `git` installed.
- AVR toolchain and make, for building and flashing:

  ```bash
  sudo apt install gcc-avr binutils-avr avr-libc avrdude build-essential
  ```

---

## 2. Getting the code

Clone the repository **once**:

```bash
git clone git@github.com:Bilal-Aston/fiber-audio-tx.git
cd fiber-audio-tx
```

Configure your identity (so we know who did what):

```bash
git config user.name "Your Name"
git config user.email "your.email@example.com"
```

---

## 3. Branching model

### 3.1 Main branch

- `main` is the **protected, stable** branch.
- Do **not** commit directly to `main`.
- All changes go through **feature branches + Pull Requests**.

### 3.2 Feature branch naming

For any task, create a new branch from `main`.

Pattern:

```text
<your-name>/<short-task-name>
```

Examples:

- `adil/timer1-pwm`
- `zimana/adc-driver`
- `sameer/timer0-pwm`

Create a branch:

```bash
git checkout main
git pull origin main
git checkout -b yourname/short-task-name
```

---

## 4. Commit message convention

Keep commits small and focused. Use **imperative present-tense**:

```text
<tag>: short description
```

Where `<tag>` is optional but helpful (e.g. `adc`, `pwm`).

Examples:

- `adc: configure channel 0 for audio sampling`
- `pwm: add 78kHz PWM output on OC1A`

Good commits answer: **“If applied, this commit will…”**.

---

## 5. Standard contribution workflow

For each piece of work (feature / bugfix):

### 5.1 Sync with main

```bash
git checkout main
git pull origin main
```

### 5.2 Create your feature branch

```bash
git checkout -b yourname/short-task-name
```

### 5.3 Work, build, and test

Edit files, then:

```bash
git status
git add <files>          # or: git add .
git commit -m "tag: short description"
```

Before pushing, check it at least builds:

```bash
make clean
make all
```

(If appropriate, also test `make flash` on hardware.)

### 5.4 Push your branch

```bash
git push -u origin yourname/short-task-name
```

### 5.5 Open a Pull Request (PR)

On GitHub:

1. You’ll see a banner: **“Compare & pull request”** then click it.
2. Set the base branch to `main`.
3. Title the PR clearly (same style as commit messages is fine).
4. In the description, explain:
   - What you changed.
   - Why you changed it.
   - How you tested it.
   - Link any related issue (e.g. `Closes #3`).

Request at least **one reviewer** from the team.

### 5.6 Review and merge

Reviewer checklist:

- Code builds (`make all`).
- Code matches project structure and style.
- No obvious bugs or dead code.
- Comments / variable names are understandable.

When the PR is approved and checks pass:

- Use **“Squash and merge”** (recommended for a clean history)  
  or **“Merge commit”** if we want to preserve individual commits.

---

## 6. Keeping your branch up to date

If `main` moves while you’re working:

```bash
git checkout main
git pull origin main
git checkout yourname/short-task-name
git merge main
```

If there are merge conflicts:

1. Fix the conflicts in the marked files.
2. Mark them as resolved:

   ```bash
   git add <fixed-files>
   git commit
   ```

3. Push again:

   ```bash
   git push
   ```

Your PR should now show **“This branch has no conflicts”**.

---

## 7. Using GitHub Issues

We use **Issues** to track work.

- Create an Issue for each task:
  - Example: `Implement ADC driver`, `Implement Timer0 Driver`, `Test PWM audio path`.
- Assign the Issue to yourself if you’re doing it.
- Use labels like `firmware`, `hardware`, etc.. where helpful.

When you open a PR, link the Issue:

- In the PR description: `Closes #<issue-number>`

This auto-closes the Issue when the PR is merged and keeps the history clear.

---

## 8. Coding & documentation guidelines

### 8.1 General code style

- Match the **existing C naming conventions in the code organisation file EXACTLY**

### 8.2 Directory structure

-Respect the existing layout & don’t invent new folders.

### 8.3 Comments

- Explain **why**, not just **what**.
- Document non-obvious hardware details (timers, prescalers, pin mappings).

---

## 9. Asking for help

If you get stuck:

1. Open an Issue describing the problem and what you’ve tried.
2. Or draft a WIP (work-in-progress) PR and clearly mark it as **“WIP”** in the title.
