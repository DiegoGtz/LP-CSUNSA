import Data.List (genericLength)

 
ejX, ejY :: [Double]
ejX = [5,  7, 10, 12, 16, 20, 23, 27, 19, 14]
ejY = [9, 11, 15, 16, 20, 24, 27, 29, 22, 20]
 
regresionLineal :: [Double] -> [Double] -> (Double,Double)
regresionLineal xs ys = (a,b)
    where n     = genericLength xs
          sumX  = sum xs
          sumY  = sum ys
          sumX2 = sum (zipWith (*) xs xs)
          sumY2 = sum (zipWith (*) ys ys)
          sumXY = sum (zipWith (*) xs ys)
          b     = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX^2)
          a     = (sumY - b*sumX) / n

          