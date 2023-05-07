#!/bin/bash

EXPECTED_HASH="24e7a7b2270daee89c64d3ca5fb3da1a -"
ACTUAL_HASH=$(cat test_data/ip_filter.tsv | ./homework_02/ip_filter | md5sum | awk '{print $1}')

if [ "$ACTUAL_HASH" != "$EXPECTED_HASH" ]; then
    echo "Hash sum mismatch. Expected: $EXPECTED_HASH. Actual: $ACTUAL_HASH."
    exit 1
fi
