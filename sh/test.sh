(
  printf "Checking Code Style... "
  standard > stdout.tmp 2> stderr.tmp && (
    echo "passed"
  ) || (
    echo "failed" >&2
    cat stderr.tmp >&2
    cat stdout.tmp
    exit 2
  )
) && (
  npm run build
) && (
  [ "$SKIP_QUICK_TEST" != 'TRUE' ] || (
    echo 'Launching product...'
    echo 'Set SKIP_QUICK_TEST to TRUE to skip this step.' >&2
    npm start
  )
)
