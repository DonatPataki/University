<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="xml" version="1.0" encoding="UTF-8" 
                doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd" 
                doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" indent="yes" />        
    <xsl:template match="udprogpoints"> 
        <html xmlns="http://www.w3.org/1999/xhtml">
            <head>
                <title>A 2017/2018 tanév .2 szemeszterének Magasszintű programozási nyelvek 1 trad. önálló munka könyvelése</title>
                <link href="points2.css" rel="stylesheet" type="text/css" />       
            </head>
            <body>
                <table class="student" cellspacing="0">                    
                    <caption>
                        <xsl:value-of select="count(student)"/> fő</caption>
                    <tr class="title">
                        <th>Rang</th>
                        <th>Név</th>
                        <th>Pont</th>
                        <th>Könyvelés</th>
                    </tr>
                    <xsl:for-each select="student">    
                        <xsl:sort select="points" data-type="number" order="descending" />                    
                        <xsl:choose>
                            <xsl:when test="(position() &gt;= 24) and (position() &lt;= 46)">
                                <tr class="offered_3">
                                    <td>
                                        <xsl:value-of select="position()"/>
                                        <xsl:text>. </xsl:text>
                                    </td>
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td class="points">          
                                        <xsl:value-of select='format-number(points, "#.0")' />
                                    </td>                            
                                    <td>
                                        <a href="{bookingurl}">
                                            <xsl:value-of select="substring(bookingurl,1,30)"/>
                                        </a>
                                    </td>
                                </tr>
                            </xsl:when>
                            <xsl:when test="(position() &gt;= 8) and (position() &lt;= 23)">
                                <tr class="offered_4">
                                    <td>
                                        <xsl:value-of select="position()"/>
                                        <xsl:text>. </xsl:text>
                                    </td>
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td class="points">          
                                        <xsl:value-of select='format-number(points, "#.0")' />
                                    </td>                            
                                    <td>
                                        <a href="{bookingurl}">
                                            <xsl:value-of select="substring(bookingurl,1,30)"/>
                                        </a>
                                    </td>
                                </tr>
                            </xsl:when>
                            <xsl:when test="position() &lt;= 7">
                                <tr class="offered_5">
                                    <td>
                                        <xsl:value-of select="position()"/>
                                        <xsl:text>. </xsl:text>
                                    </td>
                                    <td>
                                        <xsl:value-of select="name" />
                                    </td>
                                    <td class="points2">          
                                        <xsl:value-of select='format-number(points, "#.0")' />
                                    </td>                            
                                    <td>
                                        <a href="{bookingurl}">
                                            <xsl:value-of select="substring(bookingurl,1,30)"/>
                                        </a>
                                    </td>
                                </tr>
                            </xsl:when>
                            <xsl:otherwise>                            
                            <tr>
                                <td>
                                    <xsl:value-of select="position()"/>
                                    <xsl:text>. </xsl:text>
                                </td>
                                <td>
                                    <xsl:value-of select="name" />
                                </td>
                                <td class="points">          
                                        <xsl:value-of select='format-number(points, "#.0")' />
                                </td>                            
                                <td>
                                    <a href="{bookingurl}">
                                        <xsl:value-of select="substring(bookingurl,1,30)"/>
                                    </a>
                                </td>
                            </tr>                                                           
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
                </table>        
            </body>
        </html>        
    </xsl:template>
</xsl:stylesheet> 
