FROM ubuntu:20.04 AS atcoder_base

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Tokyo

RUN apt-get update && \
  apt-get install -y zsh time tzdata tree git curl

#-------------#
# build tools #
#-------------#

RUN apt-get update && \
  apt-get install -y gcc-9 g++-9 gdb libboost-all-dev
RUN apt-get update && \
  apt-get install -y python3.8 python3-pip

# make aliaces
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 30 && \
  update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 30 && \
  update-alternatives --install /usr/bin/python python /usr/bin/python3.8 30 && \
  update-alternatives --install /usr/bin/pip pip /usr/bin/pip3 30

# AtCoder Library
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

#---------------#
# support tools #
#---------------#

RUN pip install online-judge-tools==11.5.1

#-----------#
# dev tools #
#-----------#

# install VS Code (code-server)
RUN curl -fsSL https://code-server.dev/install.sh | sh

# install VS Code extensions
RUN code-server --install-extension ms-vscode.cpptools \
  --install-extension ms-vscode.cpptools-extension-pack \
  --install-extension jeff-hykin.better-cpp-syntaxk \
  --install-extension xaver.clang-format \
  --install-extension notskm.clang-tidy \
  --install-extension yzhang.markdown-all-in-one \
  --install-extension DavidAnson.vscode-markdownlint

#-----#
# zsh #
#-----#

RUN apt-get install -y fzf

#---------#
# cleanup #
#---------#

RUN apt-get clean && \ 
  rm -rf /var/lib/apt/lists/*

RUN mkdir /workspace
WORKDIR /workspace

#------#
# User #
#------#

FROM atcoder_base AS atcoder_user

ARG USERNAME=user
ARG GROUPNAME=user
ARG UID=1000
ARG GID=1000

# RUN if ! grep -q $GID /etc/group; then groupadd -g $GID $GROUPNAME; fi
# RUN if ! grep -q $UID /etc/group; then useradd -m -s /bin/zsh -u $UID -g $GID $USERNAME; fi
RUN groupadd -g $GID $GROUPNAME
RUN useradd -m -s /bin/zsh -u $UID -g $GID $USERNAME
USER $USERNAME
