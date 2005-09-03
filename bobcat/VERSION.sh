#!/bin/sh
. VERSION
echo "SUBST(_CurVers_)($VERSION)
SUBST(_CurYrs_)($YEARS)" > release.yo

