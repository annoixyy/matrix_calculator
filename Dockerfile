FROM ubuntu:22.04 AS builder

RUN apt-get update && apt-get install -y cmake g++ libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN cmake -S . -B docker-build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build docker-build

FROM ubuntu:22.04

WORKDIR /app
COPY --from=builder /app/docker-build/matrix_calculator .

CMD ["./matrix_calculator"]