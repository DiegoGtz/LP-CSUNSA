
import Data.List (genericLength)


regresionLineal :: [Double] -> [Double] -> (Double,Double)
regresionLineal xs ys = (a,b)
  where b = covarianza xs ys / varianza xs
        a = media ys - b * media xs
 
media :: [Double] -> Double
media xs = sum xs / genericLength xs
 
varianza :: [Double] -> Double
varianza xs = media ys - media xs ^ 2
  where ys = map (^2) xs 
 
covarianza :: [Double] -> [Double] -> Double
covarianza xs ys = media zs - media xs * media ys
  where zs = zipWith (*) xs ys