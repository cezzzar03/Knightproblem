FROM gcc:latest
WORKDIR /usr/src/Knight
COPY Knight.cpp .
RUN g++ -o Knight Knight.cpp
CMD ["./Knight"]