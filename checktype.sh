#!/bin/bash
TESTING_REF="master"  # Always use master for testing
OS_REF=""
APPS_REF=""

REF=$GITHUB_REF

# If a base ref is set this is a PR and we will want to use
# the base ref instead of the ref that triggered the event
if [ ${GITHUB_BASE_REF} ]; then
  REF=$GITHUB_BASE_REF
fi
  
echo "Working with ref: $REF"

# We modify for all tags and release branches
if [[ $REF =~ refs/heads/releases/*|refs/tags/* ]]; then
  if [[ $REF =~ refs/heads/* ]]
    then
      REF_NAME=${REF##refs/heads/}
      echo "Working with a branch: $REF_NAME"
    else
      REF_NAME=${REF##refs/tags/}
      echo "Working with a tag: $REF_NAME"
  fi

  # Determine the repo and leave that unset to use the normal checkout behavior
  # of using the merge commit instead of HEAD
  case $GITHUB_REPOSITORY in
    "apache/incubator-nuttx")
      # OS
      echo "Triggered by change in OS"
      APPS_REF=$REF_NAME
      ;;

    "apache/incubator-nuttx-apps")
      # APPS
      OS_REF=$REF_NAME
      echo "Triggered by change in APPS"
      ;;

    *)
      echo "Trigger by change on $GITHUB_REPOSITORY. This is unexpected."
      ;;
  esac
fi

echo ::set-output name=os_ref::$OS_REF
echo ::set-output name=apps_ref::$APPS_REF
echo ::set-output name=testing_ref::$TESTING_REF