#!/bin/bash
cd $2/
zip  firmware-$1.zip $3.bin bootloader/bootloader.bin partition_table/partition-table.bin