import sys
import numpy

def maxCross(a: list, low: int, mid: int, high: int):
    leftSummation = -100000
    Summation = 0
    i = mid
    maxLeft = None

    while i >= low:
        Summation = Summation + a[i]
        if Summation > leftSummation:
            leftSummation = Summation
            maxLeft = i
        i -= 1
    rightSummation = -100000
    Summation = 0
    j = mid+1
    maxRight = None

    while j <= high:
        Summation = Summation + a[j]
        if Summation > rightSummation:
            rightSummation = Summation
            maxRight = j
        j += 1
    return maxLeft, maxRight, leftSummation + rightSummation


def maxSubArray(a: list, low: int, high: int):
    if high == low:
        return low, high, a[low]
    else:
        mid = (low + high)//2
        leftLow, leftHigh, leftSummation = maxSubArray(a, low, mid)
        rightLow, rightHigh, rightSummation = maxSubArray(a, mid+1, high)
        crossLow, crossHigh, crossSummation = maxCross(a, low, mid, high)
        if (leftSummation >= rightSummation) and (leftSummation >= crossSummation):
            return leftLow, leftHigh, leftSummation
        elif (rightSummation >= leftSummation) and (rightSummation >= crossSummation):
            return rightLow, rightHigh, rightSummation
        else:
            return crossLow, crossHigh, crossSummation

def main():
    testCase = numpy.random.randint(low=-50, high=50, size=100).tolist()
    print(testCase)
    firstIdx, lastIdx, maxSummation=(maxSubArray(testCase, 0, 100-1))
    print(f"first : {firstIdx} , last: {lastIdx}, max-sum : {maxSummation}")


if __name__ == "__main__":
    main()