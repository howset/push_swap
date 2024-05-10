# Eval copy paste, with valgrind for convenience
## Error Management
- Non-numeric parameters
```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap a bb ccc
```
- Duplicate numeric parameters
```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 3 1
```
- Only numeric, one greater than maxint (2147483647)
```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 5 2147483648 1
```
- No parameters
```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap
```
## Identity Test
- 1 parameter
```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 42
```
- sorted list
```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 0 1 2 3
```
- sorted list, longer
```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 0 1 2 3 4 5 6 7 8 9
```
## Simple Version
- list size must be 2 or 3
```bash
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
```
## Another Simple Version
- list size must not exceed 12
```bash
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
```
- random values, must not exceed 12
```bash
ARG="13 2 64 85 200"; ./push_swap $ARG | ./checker_linux $ARG
```
## Middle Version
- No points if fail. Move to the next one! Move to the next one! Move to the next one!
```bash
ARG="<100 randos>"; ./push_swap $ARG | ./checker_linux $ARG
```
[https://numbergenerator.org/](https://numbergenerator.org/)
- Radix on 100 nums - 1084

## Advanced Version
- No points if fail. Move to the next one! Move to the next one! Move to the next one!
```bash
ARG="<500 randos>"; ./push_swap $ARG | ./checker_linux $ARG
```
[https://numbergenerator.org/](https://numbergenerator.org/)
- Radix on 500 nums - 6784

## Verifications
- Visualizer [https://github.com/o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- Visualizer [https://gitlab.com/nda-cunh/visualizer-push-swap](https://gitlab.com/nda-cunh/visualizer-push-swap) (not tried in cluster)
- Tester [https://github.com/gemartin99/Push-Swap-Tester](https://github.com/gemartin99/Push-Swap-Tester)