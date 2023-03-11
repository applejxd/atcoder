#!/bin/zsh

#----#
# oj #
#----#

# サイトログイン
oj login https://atcoder.jp/

# コンパイル・チェック自動化. 追加引数使用可能.
# ojt -> oj s で提出可能
# cf. https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md
function ojt() {
  url=$1
  name=$2

  oj download "$url"
  fname=$(echo "$name" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$name" -o "$fname"
  shift 2
  oj test -c ./"$fname" "$@"

  rm -f "$fname"
  rm -rf test
}

#-------#
# build #
#-------#

function runcpp() {
  fname=$(echo "$1" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$1" -o "$fname"
  shift
  ./"$fname" "$@"
}
alias -s {c,cc,cpp}='runcpp'

#-------#
# zinit #
#-------#

### Added by Zinit's installer
if [[ ! -f $HOME/.zinit/bin/zinit.zsh ]]; then
    print -P "%F{33}▓▒░ %F{220}Installing DHARMA Initiative Plugin Manager (zdharma/zinit)…%f"
    command mkdir -p "$HOME/.zinit" && command chmod g-rwX "$HOME/.zinit"
    command git clone https://github.com/zdharma-continuum/zinit "$HOME/.zinit/bin" && \
        print -P "%F{33}▓▒░ %F{34}Installation successful.%f%b" || \
        print -P "%F{160}▓▒░ The clone has failed.%f%b"
fi

source "$HOME/.zinit/bin/zinit.zsh"
autoload -Uz _zinit
(( ${+_comps} )) && _comps[zinit]=_zinit
### End of Zinit's installer chunk

# fish-like auto completion
zinit light zsh-users/zsh-autosuggestions
# completion for non-defalut commands
zinit light zsh-users/zsh-completions
# Fish like interactive tab completion for cd in zsh
zinit ice pick"zsh-interactive-cd.plugin.zsh" wait'!0'
zinit light changyuheng/zsh-interactive-cd
# syntax-highlighting to command-line (after compinit)
zinit ice wait'!0'
zinit light zsh-users/zsh-syntax-highlighting

# Pure Theme
zinit ice compile'(pure|async).zsh' pick'async.zsh' src'pure.zsh'
zinit light sindresorhus/pure
zinit ice from"gh-r" as"program"
zinit load junegunn/fzf-bin

# fzf
zinit ice multisrc'shell/(key-bindings|completion).zsh'
zinit load junegunn/fzf
# z
zinit ice pick"z.sh"
zinit light rupa/z

#-----#
# zsh #
#-----#

# cd completion
# cf. http://bit.ly/2ZtPPrN
setopt auto_cd
cdpath=(.. ~)
function chpwd() {
  if type "lsd" >/dev/null 2>&1; then
    lsd
  else
    ls
  fi
}

# z-fzf, emacs-like key-bindings
# cf. http://bit.ly/2sEPZAJ
if type "z" >/dev/null 2>&1; then
    function z-fzf() {
        local selected_dir=$(_z -l 2>&1 | fzf +s --tac | sed 's/^[0-9,.]* *//')
        if [[ -n "$selected_dir" ]]; then
            BUFFER="cd ${selected_dir}"
            zle accept-line
        fi
        zle reset-prompt
    }
    zle -N z-fzf
    bindkey "^X^F" z-fzf
fi