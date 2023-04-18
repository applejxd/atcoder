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

alias ojp=oj-prepare


#--------#
# Prompt #
#--------#

autoload -Uz vcs_info
precmd() { 
  vcs_info 
}
zstyle ':vcs_info:git:*' formats '%b '
setopt PROMPT_SUBST
PROMPT='%F{green}%*%f %F{blue}%~%f %F{red}${vcs_info_msg_0_}%f$ '
