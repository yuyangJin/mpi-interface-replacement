MIR_DIR=/home/jinyuyang/PACMAN_PROJECT/huawei21/mpi-interface-replacement

$MIR_DIR/bin/dataFlowGraph $MIR_DIR/example/$1.c

dot -Tpdf $1.c.dot -o $1.c.pdf
