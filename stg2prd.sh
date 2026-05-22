#!/bin/bash
CURRENT_BRANCH=$(git branch --show-current)

git checkout prd
git pull origin prd
git merge stg -m "Merge stg into prd"

TAG_NAME="prd-$(date +'%Y-%m-%d_%H-%M-%S')"
git tag -a "$TAG_NAME" -m "Staging deployment $TAG_NAME"

git push origin prd
git push origin "$TAG_NAME"

git checkout "$CURRENT_BRANCH"

echo "stg2prd DONE. Tag: $TAG_NAME"
