# cf. https://qiita.com/hinamimi/items/b3dd159f956628cebdbb
FROM amd64/ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Tokyo

RUN apt-get update && \
  apt-get install -y zsh time tzdata tree git curl

#-------------#
# build tools #
#-------------#

# install build tools and libraries
RUN apt-get update && \
  apt-get install -y gcc-9 g++-9 gdb clang-format libboost-all-dev
# install python dev env
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

RUN pip install online-judge-tools==11.5.1 \
  online-judge-template-generator==4.8.1

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

RUN chsh -s /bin/zsh
COPY .zshrc /root/.zshrc

RUN mkdir /workspace
WORKDIR /workspace

RUN mkdir -p /root/.config/online-judge-tools
COPY prepare.config.toml /root/.config/online-judge-tools
