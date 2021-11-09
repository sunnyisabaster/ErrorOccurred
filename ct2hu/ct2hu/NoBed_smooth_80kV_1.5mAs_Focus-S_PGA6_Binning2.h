#ifndef _Catphan_80kV_1mAs_Focus_S_PGA6_Binning2_hpp_
#define _Catphan_80kV_1mAs_Focus_S_PGA6_Binning2_hpp_

class Catphan_Focus_S_PGA6_Binning2 {
public:
    Catphan_Focus_S_PGA6_Binning2() {

    }
    float* get_kval()
    {
        return K_val;
    }
    double* get_dis()
    {
        return dis;
    }

    float* get_ct_val()
    {
        return ct_val;
    }

    float* get_Hu_val()
    {
        return Hu_val;
    }
    int get_indexLength()
    {
        return indexLength;
    }
private:
    int indexLength = 441;
    float K_val[441] = { 3809.02531696312, 3815.934593389192, 3822.8476553054, 3829.7644388882186, 3836.684879953511, 3843.608913957152, 3850.536475995675, 3857.467500806949, 3864.401922770878, 3871.3396759101324, 3878.280693890902, 3885.2249100236804, 3892.1722572640756, 3899.1226682136457, 3906.0760751207663, 3913.032409881521, 3919.9916040406238, 3926.953588792369, 3933.918294981604, 3940.885653104739, 3947.855593310779, 3954.828045402384, 3961.8029388369623, 3968.78020272779, 3975.7597658451577, 3982.74155661755, 3989.7255031328514, 3996.7115331395808, 4003.6995740481607, 4010.689552932207, 4017.6813965298575, 4024.675031245124, 4031.6703831492778, 4038.667377982261, 4045.665941154132, 4052.6659977465406, 4059.66747251423, 4066.670289886571, 4073.674373969129, 4080.679648545259, 4087.686037077728, 4094.693462710374, 4101.701848269795, 4108.711116267063, 4115.721188899473, 4122.731988052328, 4129.74343530074, 4136.755451911481, 4143.767958844849, 4150.780876756573, 4157.794125999752, 4164.807626626818, 4171.82129839153, 4178.835060751008, 4185.848832867792, 4192.86253361193, 4199.876081563108, 4206.889395012792, 4213.902391966428, 4220.91499014565, 4227.927106990529, 4234.938659661858, 4241.949565043458, 4248.959739744528, 4255.96910010201, 4262.977562183007, 4269.9850417872085, 4276.99145444937, 4283.996715441808, 4291.000739776932, 4298.003442209812, 4305.00473724077, 4312.0045391180065, 4319.00276184026, 4325.999319159495, 4332.994124583623, 4339.987091379251, 4346.97813257447, 4353.967160961662, 4360.95408910035, 4367.938829320072, 4374.921293723286, 4381.90139418831, 4388.879042372292, 4395.854149714203, 4402.826627437872, 4409.796386555044, 4416.763337868471, 4423.727391975034, 4430.688459268891, 4437.646449944664, 4444.601274000641, 4451.552841242028, 4458.5010612842125, 4465.4458435560655, 4472.387097303276, 4479.324731591701, 4486.258655310764, 4493.188777176869, 4500.115005736845, 4507.037249371425, 4513.955416298749, 4520.8694145778945, 4527.779152112442, 4534.684536654062, 4541.585475806128, 4548.4818770273705, 4555.37364763554, 4562.260694811112, 4569.142925601015, 4576.020246922383, 4582.892565566335, 4589.759788201786, 4596.621821379275, 4603.478571534836, 4610.329944993874, 4617.175847975079, 4624.016186594369, 4630.850866868846, 4637.679794720789, 4644.502875981662, 4651.320016396154, 4658.13112162624, 4664.936097255267, 4671.734848792059, 4678.527281675058, 4685.31330127647, 4692.092812906453, 4698.865721817312, 4705.631933207727, 4712.391352226998, 4719.143883979308, 4725.889433528022, 4732.627905899992, 4739.3592060898845, 4746.083239064542, 4752.7999097673455, 4759.509123122619, 4766.210784040027, 4772.904797419015, 4779.59106815326, 4786.269501135133, 4792.940001260195, 4799.602473431691, 4806.256822565084, 4812.902953592588, 4819.540771467728, 4826.1701811699095, 4832.791087709011, 4839.403396129989, 4846.007011517499, 4852.601839000532, 4859.187783757061, 4865.764751018709, 4872.332646075425, 4878.891374280184, 4885.440841053678, 4891.980951889048, 4898.511612356606, 4905.032728108577, 4911.544204883859, 4918.0459485127785, 4924.537864921875, 4931.019860138679, 4937.49184029651, 4943.953711639285, 4950.405380526327, 4956.846753437184, 4963.277736976472, 4969.698237878701, 4976.108163013125, 4982.507419388591, 4988.895914158405, 4995.273554625183, 5001.640248245734, 5007.9959026359265, 5014.3404255755695, 5020.673725013295, 5026.995709071445, 5033.306286050965, 5039.605364436291, 5045.892852900242, 5052.168660308931, 5058.43269572664, 5064.68486842074, 5070.925087866575, 5077.1532637523715, 5083.3693059841235, 5089.573124690503, 5095.764630227746, 5101.943733184549, 5108.110344386957, 5114.264374903255, 5120.405736048847, 5126.534339391143, 5132.6500967544225, 5138.752920224717, 5144.842722154668, 5150.919415168385, 5156.982912166302, 5163.033126330019, 5169.069971127138, 5175.093360316101, 5181.103207951002, 5187.099428386402, 5193.081936282133, 5199.05064660809, 5205.005474649011, 5210.946336009254, 5216.873146617549, 5222.785822731749, 5228.684280943569, 5234.568438183302, 5240.438211724529, 5246.293519188819, 5252.134278550403, 5257.960408140842, 5263.7718266536785, 5269.568453149065, 5275.350207058389, 5281.117008188868, 5286.868776728133, 5292.605433248796, 5298.326898712997, 5304.033094476928, 5309.723942295349, 5315.399364326064, 5321.059283134406, 5326.7036216976685, 5332.332303409545, 5337.945252084522, 5343.542391962269, 5349.123647711996, 5354.688944436789, 5360.238207677921, 5365.771363419145, 5371.2883380909525, 5376.789058574815, 5382.273452207398, 5387.741446784748, 5393.192970566451, 5398.6279522797695, 5404.046321123746, 5409.448006773283, 5414.832939383199, 5420.201049592241, 5425.552268527083, 5430.886527806288, 5436.203759544243, 5441.503896355061, 5446.78687135645, 5452.052618173562, 5457.301070942791, 5462.532164315561, 5467.745833462065, 5472.942014074978, 5478.120642373137, 5483.281655105184, 5488.4249895531775, 5493.550583536172, 5498.658375413753, 5503.748304089553, 5508.820309014714, 5513.874330191328, 5518.910308175831, 5523.928184082367, 5528.927899586119, 5533.909396926585, 5538.872618910838, 5543.8175089167335, 5548.744010896083, 5553.652069377787, 5558.541629470938, 5563.412636867867, 5568.265037847169, 5573.098779276671, 5577.913808616376, 5582.710073921354, 5587.487523844598, 5592.2461076398395, 5596.985775164318, 5601.706476881511, 5606.408163863824, 5611.090787795237, 5615.754300973906, 5620.398656314725, 5625.023807351842, 5629.629708241139, 5634.216313762651, 5638.783579322968, 5643.331460957562, 5647.8599153331, 5652.368899749688, 5656.8583721430905, 5661.328291086882, 5665.778615794579, 5670.20930612171, 5674.620322567842, 5679.011626278568, 5683.383179047442, 5687.734943317874, 5692.066882184971, 5696.378959397343, 5700.6711393588475, 5704.943387130305, 5709.195668431151, 5713.427949641059, 5717.640197801495, 5721.832380617246, 5726.004466457884, 5730.156424359202, 5734.288224024581, 5738.399835826326, 5742.491230806945, 5746.562380680389, 5750.6132578332345, 5754.643835325826, 5758.654086893369, 5762.64398694697, 5766.613510574639, 5770.562633542234, 5774.491332294361, 5778.399583955231, 5782.287366329461, 5786.154657902833, 5790.001437843, 5793.827686000152, 5797.6333829076275, 5801.418509782472, 5805.183048525965, 5808.9269817240865, 5812.650292647934, 5816.352965254102, 5820.034984185005, 5823.696334769155, 5827.337003021397, 5830.956975643089, 5834.556240022236, 5838.134784233583, 5841.692597038649, 5845.229667885732, 5848.745986909843, 5852.241544932616, 5855.7163334621555, 5859.170344692843, 5862.603571505098, 5866.016007465089, 5869.407646824403, 5872.778484519662, 5876.128516172099, 5879.457738087088, 5882.766147253621, 5886.053741343751, 5889.320518711982, 5892.5664783946095, 5895.791620109025, 5898.995944252978, 5902.179451903777, 5905.342144817464, 5908.484025427931, 5911.605096846002, 5914.705362858471, 5917.784827927084, 5920.843497187491, 5923.881376448154, 5926.898472189198, 5929.894791561243, 5932.870342384167, 5935.825133145848, 5938.759173000851, 5941.672471769082, 5944.565039934392, 5947.436888643149, 5950.2880297027605, 5953.118475580161, 5955.928239400259, 5958.717334944337, 5961.485776648424, 5964.233579601613, 5966.9607595443595, 5969.667332866719, 5972.35331660656, 5975.01872844774, 5977.663586718226, 5980.287910388206, 5982.891719068138, 5985.47503300677, 5988.037873089133, 5990.580260834482, 5993.102218394208, 5995.603768549721, 5998.08493471029, 6000.545740910847, 6002.986211809759, 6005.406372686568, 6007.806249439696, 6010.185868584115, 6012.54525724898, 6014.884443175242, 6017.203454713214, 6019.502320820114, 6021.781071057575, 6024.039735589118, 6026.278345177606, 6028.496931182653, 6030.695525558013, 6032.87416084894, 6035.03287018951, 6037.171687299918, 6039.290646483759, 6041.389782625254, 6043.469131186476, 6045.528728204529, 6047.568610288716, 6049.588814617661, 6051.589378936427, 6053.570341553589, 6055.531741338294, 6057.473617717296, 6059.396010671956, 6061.298960735225, 6063.182508988608, 6065.046697059099, 6066.891567116089, 6068.717161868265, 6070.523524560468, 6072.310698970552, 6074.078729406198, 6075.827660701735, 6077.557538214906, 6079.268407823652, 6080.96031592284, 6082.633309421007, 6084.2874357370565, 6085.922742796952, 6087.539279030392, 6089.13709336746, 6090.716235235267, 6092.276754554573, 6093.818701736388, 6095.342127678569 };
    double dis[441] = { 0.25,   0.5 ,   0.75,   1.  ,   1.25,   1.5 ,   1.75,   2.  ,
         2.25,   2.5 ,   2.75,   3.  ,   3.25,   3.5 ,   3.75,   4.  ,
         4.25,   4.5 ,   4.75,   5.  ,   5.25,   5.5 ,   5.75,   6.  ,
         6.25,   6.5 ,   6.75,   7.  ,   7.25,   7.5 ,   7.75,   8.  ,
         8.25,   8.5 ,   8.75,   9.  ,   9.25,   9.5 ,   9.75,  10.  ,
        10.25,  10.5 ,  10.75,  11.  ,  11.25,  11.5 ,  11.75,  12.  ,
        12.25,  12.5 ,  12.75,  13.  ,  13.25,  13.5 ,  13.75,  14.  ,
        14.25,  14.5 ,  14.75,  15.  ,  15.25,  15.5 ,  15.75,  16.  ,
        16.25,  16.5 ,  16.75,  17.  ,  17.25,  17.5 ,  17.75,  18.  ,
        18.25,  18.5 ,  18.75,  19.  ,  19.25,  19.5 ,  19.75,  20.  ,
        20.25,  20.5 ,  20.75,  21.  ,  21.25,  21.5 ,  21.75,  22.  ,
        22.25,  22.5 ,  22.75,  23.  ,  23.25,  23.5 ,  23.75,  24.  ,
        24.25,  24.5 ,  24.75,  25.  ,  25.25,  25.5 ,  25.75,  26.  ,
        26.25,  26.5 ,  26.75,  27.  ,  27.25,  27.5 ,  27.75,  28.  ,
        28.25,  28.5 ,  28.75,  29.  ,  29.25,  29.5 ,  29.75,  30.  ,
        30.25,  30.5 ,  30.75,  31.  ,  31.25,  31.5 ,  31.75,  32.  ,
        32.25,  32.5 ,  32.75,  33.  ,  33.25,  33.5 ,  33.75,  34.  ,
        34.25,  34.5 ,  34.75,  35.  ,  35.25,  35.5 ,  35.75,  36.  ,
        36.25,  36.5 ,  36.75,  37.  ,  37.25,  37.5 ,  37.75,  38.  ,
        38.25,  38.5 ,  38.75,  39.  ,  39.25,  39.5 ,  39.75,  40.  ,
        40.25,  40.5 ,  40.75,  41.  ,  41.25,  41.5 ,  41.75,  42.  ,
        42.25,  42.5 ,  42.75,  43.  ,  43.25,  43.5 ,  43.75,  44.  ,
        44.25,  44.5 ,  44.75,  45.  ,  45.25,  45.5 ,  45.75,  46.  ,
        46.25,  46.5 ,  46.75,  47.  ,  47.25,  47.5 ,  47.75,  48.  ,
        48.25,  48.5 ,  48.75,  49.  ,  49.25,  49.5 ,  49.75,  50.  ,
        50.25,  50.5 ,  50.75,  51.  ,  51.25,  51.5 ,  51.75,  52.  ,
        52.25,  52.5 ,  52.75,  53.  ,  53.25,  53.5 ,  53.75,  54.  ,
        54.25,  54.5 ,  54.75,  55.  ,  55.25,  55.5 ,  55.75,  56.  ,
        56.25,  56.5 ,  56.75,  57.  ,  57.25,  57.5 ,  57.75,  58.  ,
        58.25,  58.5 ,  58.75,  59.  ,  59.25,  59.5 ,  59.75,  60.  ,
        60.25,  60.5 ,  60.75,  61.  ,  61.25,  61.5 ,  61.75,  62.  ,
        62.25,  62.5 ,  62.75,  63.  ,  63.25,  63.5 ,  63.75,  64.  ,
        64.25,  64.5 ,  64.75,  65.  ,  65.25,  65.5 ,  65.75,  66.  ,
        66.25,  66.5 ,  66.75,  67.  ,  67.25,  67.5 ,  67.75,  68.  ,
        68.25,  68.5 ,  68.75,  69.  ,  69.25,  69.5 ,  69.75,  70.  ,
        70.25,  70.5 ,  70.75,  71.  ,  71.25,  71.5 ,  71.75,  72.  ,
        72.25,  72.5 ,  72.75,  73.  ,  73.25,  73.5 ,  73.75,  74.  ,
        74.25,  74.5 ,  74.75,  75.  ,  75.25,  75.5 ,  75.75,  76.  ,
        76.25,  76.5 ,  76.75,  77.  ,  77.25,  77.5 ,  77.75,  78.  ,
        78.25,  78.5 ,  78.75,  79.  ,  79.25,  79.5 ,  79.75,  80.  ,
        80.25,  80.5 ,  80.75,  81.  ,  81.25,  81.5 ,  81.75,  82.  ,
        82.25,  82.5 ,  82.75,  83.  ,  83.25,  83.5 ,  83.75,  84.  ,
        84.25,  84.5 ,  84.75,  85.  ,  85.25,  85.5 ,  85.75,  86.  ,
        86.25,  86.5 ,  86.75,  87.  ,  87.25,  87.5 ,  87.75,  88.  ,
        88.25,  88.5 ,  88.75,  89.  ,  89.25,  89.5 ,  89.75,  90.  ,
        90.25,  90.5 ,  90.75,  91.  ,  91.25,  91.5 ,  91.75,  92.  ,
        92.25,  92.5 ,  92.75,  93.  ,  93.25,  93.5 ,  93.75,  94.  ,
        94.25,  94.5 ,  94.75,  95.  ,  95.25,  95.5 ,  95.75,  96.  ,
        96.25,  96.5 ,  96.75,  97.  ,  97.25,  97.5 ,  97.75,  98.  ,
        98.25,  98.5 ,  98.75,  99.  ,  99.25,  99.5 ,  99.75, 100.  ,
       100.25, 100.5 , 100.75, 101.  , 101.25, 101.5 , 101.75, 102.  ,
       102.25, 102.5 , 102.75, 103.  , 103.25, 103.5 , 103.75, 104.  ,
       104.25, 104.5 , 104.75, 105.  , 105.25, 105.5 , 105.75, 106.  ,
       106.25, 106.5 , 106.75, 107.  , 107.25, 107.5 , 107.75, 108.  ,
       108.25, 108.5 , 108.75, 109.  , 109.25, 109.5 , 109.75, 110.  ,
       110.25 };

    float Hu_val[5] = { -1000, -200, 0,  340 ,1000 };
    //float ct_val[5] = { 49.42167144011241, 87.62246810223743, 97.85943784164283, 114.38938110223695 , 144.20280252142084 };
    float ct_val[5] = { 55.42167144011241, 87.62246810223743, 99.85943784164283, 114.38938110223695 , 144.20280252142084 };
    //float Hu_val[5] = { 0 ,1000 };
};
#endif //__Catphan_Focus_S_PGA6_Binning2__hpp_