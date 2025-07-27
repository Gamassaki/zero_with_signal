# 🔍 zero_with_signal_portable

Uma função genérica em C que detecta se um valor numérico possui **bit de sinal ativado**, mesmo para casos como `-0.0` em `float` e `double`. Funciona corretamente em sistemas **little-endian** e **big-endian**.

---

## 🧠 Objetivo

Este projeto demonstra como interpretar os bytes de diferentes tipos numéricos (`int`, `float`, `double`, etc.) e verificar se o **bit de sinal** está ativado, independentemente da arquitetura do sistema.

Casos como `-0.0` em ponto flutuante (IEEE 754) possuem o bit de sinal ativo, mesmo que o valor matemático seja zero. Esta função permite detectar esse tipo de situação.

---

## ⚙️ Função principal

```c
int zero_with_signal_portable(void *nbr, size_t size);

---

## Retorno
1: se o valor tiver bit de sinal ativado.

0: caso contrário