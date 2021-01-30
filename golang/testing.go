
package main
import (
"testing"
"github.com/stretchr/testify/suite"
"github.com/vgasparini/go_course/fib"
)
type FibSuite struct {
suite.Suite
}
func (suite *FibSuite) TestFib() {
suite.Equal(uint(0), Fib(0))
suite.Equal(uint(1), Fib(1))
suite.Equal(uint(1), Fib(2))
}
func TestFibSuite(t *testing.T) {
suite.Run(t, &FibSuite{})
}
