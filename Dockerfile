FROM ubuntu:22.04 AS builder
RUN apt-get update && \
 apt-get install -y cmake g++ libgtest-dev git && \
 rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
RUN cmake -B build && \
 cmake --build build --target rpn_calculator --parallel 2
FROM ubuntu:22.04
WORKDIR /app
COPY --from=builder /app/build/rpn_calculator .
CMD ["./rpn_calculator"]