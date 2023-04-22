# cf. https://qiita.com/hinamimi/items/b3dd159f956628cebdbb
FROM amd64/python:3.8.16-bullseye

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Tokyo

RUN apt-get update && \
  apt-get install --no-install-recommends -y \
  time=1.9-0.1 \
  tree=1.8.0-1+b1 \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

#-------------#
# build tools #
#-------------#

# install build tools and libraries
RUN apt-get update && \
  apt-get install  --no-install-recommends -y \
  gcc-9=9.3.0-22 \
  g++-9=9.3.0-22 \
  gdb=10.1-1.7 \
  clang-format=1:11.0-51+nmu5 \
  libboost-all-dev=1.74.0.3 \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

# make aliaces
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 30 && \
  update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 30

# AtCoder Library
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library -b v1.4
ENV CPLUS_INCLUDE_PATH /lib/ac-library

#---------------#
# support tools #
#---------------#

RUN pip install --no-cache-dir \
  online-judge-tools==11.5.1 \
  online-judge-template-generator==4.8.1

#-----#
# zsh #
#-----#

RUN apt-get update && \
  apt-get install --no-install-recommends -y \
  zsh=5.8-6+deb11u1 \
  fzf=0.24.3-1+b6 \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

#--------#
# config #
#--------#

RUN mkdir /workspace

ENV USER=atcoder
RUN useradd -m -s /bin/zsh $USER && chown -R $USER /workspace
COPY .zshrc /home/$USER/.zshrc

RUN mkdir -p /home/$USER/.config
COPY online-judge-tools/ /home/$USER/.config/online-judge-tools/

COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

USER atcoder
WORKDIR /workspace
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]