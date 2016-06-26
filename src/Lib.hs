{-# LANGUAGE ForeignFunctionInterface #-}
{-# LANGUAGE TemplateHaskell          #-}
module Lib where

import           Foreign.C

double :: Int -> Int
double = (*2)

foreign export ccall double_export :: CInt -> CInt
double_export = fromIntegral . double . fromIntegral


-- newCompleter :: IO InputReceiver
-- newCompleter = undefined

-- -- null == end of candidates
-- addCandidate :: CString -> InputReceiver -> IO (Maybe CompletionHandle)
-- addCandidate = undefined

-- addKey :: Char -> CompletionHandle -> IO ()
-- addKey = undefined

-- getCompletion :: CompletionHandle -> Int -> IO CString
