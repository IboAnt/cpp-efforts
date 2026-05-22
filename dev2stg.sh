#!/bin/bash
CURRENT_BRANCH=$(git branch --show-current)

git checkout stg
git pull origin stg
git merge dev -m "Merge dev into stg"

TAG_NAME="stg-$(date +'%Y-%m-%d_%H-%M-%S')"
git tag -a "$TAG_NAME" -m "Staging deployment $TAG_NAME"

git push origin stg
git push origin "$TAG_NAME"

git checkout "$CURRENT_BRANCH"

echo "dev2stg DONE. Tag: $TAG_NAME"
