FROM debian

RUN apt-get update \
 && apt-get install -y build-essential clang curl git vim cmake afl \
# && apt-get install -y libcurl4-openssl-dev libssl-dev \
 && apt-get install -y cppcheck \
 && apt-get install -y valgrind \
 && apt-get install -y lcov \
 && adduser --gecos "" --disabled-password fuzz

USER fuzz:fuzz
WORKDIR /home/fuzz
# Install curl/openssl
RUN CURL_URL="https://curl.haxx.se/download/curl-7.65.3.tar.xz" \
# Note 1.1.1c has some bug with conditionals depending on unintialized data and -DPURIFY
# does nothing anymore: https://github.com/openssl/openssl/issues/8460 https://www.openssl.org/news/changelog.txt
# && OPENSSL_URL="https://www.openssl.org/source/openssl-1.1.1c.tar.gz" \
 && OPENSSL_URL="https://www.openssl.org/source/openssl-1.1.0k.tar.gz" \
 && curl -LO "$CURL_URL" \
 && curl -LO "$OPENSSL_URL"
RUN mkdir curl && tar xf curl*.tar* -C curl && rm curl*.tar*
RUN mkdir ssl  && tar xf *ssl*.tar* -C ssl  && rm *ssl*.tar*
RUN cd /home/fuzz/curl && mv curl* src && mkdir install
RUN cd /home/fuzz/ssl  && mv *ssl* src && mkdir install
RUN cd /home/fuzz/ssl/src \
 &&   ./config --prefix="/home/fuzz/ssl/install" -fPIC -DPURIFY \
 &&   make -j8  \
 &&   make install
RUN cd /home/fuzz/curl/src \
#     Need this export to find the openssl shared libraries when building
#     See https://github.com/curl/curl/issues/1420
 &&   export LD_LIBRARY_PATH="/home/fuzz/ssl/install/lib/" \
 &&   ./configure --prefix="/home/fuzz/curl/install" -with-ssl="/home/fuzz/ssl/install" \
 &&   make -j8  \
 &&   make install \
# Create libraries with certain symbols renamed
 && cd /home/fuzz \
 && objcopy \
      --redefine-sym curl_easy_perform=rcurl_easy_perform \
      --redefine-sym curl_easy_setopt=rcurl_easy_setopt \
      /home/fuzz/curl/install/lib/libcurl.a \
      /home/fuzz/curl/install/lib/libcurl_fuzz.a \
 && objcopy \
      --redefine-sym EVP_DigestVerifyInit=rEVP_DigestVerifyInit \
      --redefine-sym EVP_DigestUpdate=rEVP_DigestUpdate \
      --redefine-sym EVP_DigestVerifyFinal=rEVP_DigestVerifyFinal \
      /home/fuzz/ssl/install/lib/libcrypto.a \
      /home/fuzz/ssl/install/lib/libcrypto_fuzz.a \
 && objcopy \
      --redefine-sym BN_bin2bn=rBN_bin2bn \
      --redefine-sym BN_new=rBN_new \
      --redefine-sym BN_secure_new=rBN_secure_new \
      --redefine-sym EVP_MD_CTX_new=rEVP_MD_CTX_new \
      --redefine-sym EVP_PKEY_new=rEVP_PKEY_new \
      --redefine-sym EVP_PKEY_set1_RSA=rEVP_PKEY_set1_RSA \
      --redefine-sym EVP_DigestVerifyInit=rEVP_DigestVerifyInit \
      --redefine-sym EVP_DigestUpdate=rEVP_DigestUpdate \
      --redefine-sym EVP_DigestVerifyFinal=rEVP_DigestVerifyFinal \
      --redefine-sym RSA_new=rRSA_new \
      --redefine-sym RSA_set0_key=rRSA_set0_key \
      /home/fuzz/ssl/install/lib/libcrypto.a \
      /home/fuzz/ssl/install/lib/libcrypto_chaos.a
# googletest
RUN git clone https://github.com/google/googletest.git \
 && mkdir /home/fuzz/googletest/googletest/build \
 && cd /home/fuzz/googletest/googletest/build \
 && cmake .. \
 && make -j4
# Install infer
RUN curl -LO "https://github.com/facebook/infer/releases/download/v0.17.0/infer-linux64-v0.17.0.tar.xz"
RUN echo "de972ba3043f18b29a8eff6cd7612e24f5ffaef038dc7949befeaf490931725e  infer-linux64-v0.17.0.tar.xz" | sha256sum -c \
 && tar xJf infer-linux64-v0.17.0.tar.xz \
 && rm infer-linux64-v0.17.0.tar.xz \
 && mv infer* infer \
 && echo 'export PATH="/home/fuzz/infer/bin:$PATH"' >> /home/fuzz/.bashrc


USER fuzz:fuzz


# mkdir build
# cd build
# cmake -DCMAKE_C_COMPILER="afl-gcc" -DCMAKE_CXX_COMPILER="afl-g++" ../
